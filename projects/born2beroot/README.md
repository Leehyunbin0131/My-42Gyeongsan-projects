*This project has been created as part of the 42 curriculum by hyunlee.*

# Born2beRoot

## Description

**Born2beRoot**는 가상화 환경(VirtualBox)에서 리눅스 서버 운영체제를 직접 설치하고, 엄격한 시스템 관리 및 보안 규칙에 따라 서버를 구성하는 시스템 어드미니스트레이션(System Administration) 프로젝트입니다.

이 프로젝트의 주요 목표는 다음과 같습니다:
- GUI(X.org, Wayland 등) 없이 최소한의 서비스만 구동되는 **Minimal Server** 환경 구축
- **LVM(Logical Volume Manager)** 및 **LUKS 디스크 암호화**를 활용한 안전한 파티셔닝 설계
- **SELinux**, **firewalld**, **SSH(`4242` 포트, `root` 접속 차단)**를 통한 네트워크 및 시스템 접근 제어
- **PAM(`pam_pwquality`)** 및 `/etc/login.defs`, `chage`를 통한 강력한 비밀번호 정책 수립
- **sudo** 권한 제어 및 입출력(I/O) 아카이빙 로깅 구성
- **Bash 스크립트(`monitoring.sh`)**와 **cron** 스케줄러를 이용한 주기적 서버 상태 모니터링 구현

---

## Project Description

### 1. 운영체제 선택: Rocky Linux 10.2 Minimal

본 프로젝트에서는 **Rocky Linux 10.2 (Minimal Install)**를 선택했습니다.
Rocky Linux는 Red Hat Enterprise Linux(RHEL)의 다운스트림 호환 배포판으로, 엔터프라이즈 환경에서 표준으로 사용되는 **SELinux(강제 접근 제어)**와 **firewalld(동적 방화벽)**가 기본 내장되어 있어 실무 서버 보안 구성을 깊이 있게 학습할 수 있습니다.

### 2. 주요 설계 및 구성 선택 (Main Design Choices)

- **파티셔닝 및 암호화 (Partitioning & Encryption)**
  - 가상 디스크(VDI)에 `GPT` 파티션 테이블을 적용했습니다.
  - Legacy BIOS 부팅을 위한 `BIOS Boot` 파티션과 커널 로드를 위한 비암호화 `/boot`(`ext4`) 파티션을 분리했습니다.
  - 나머지 영역은 **LUKS 암호화**가 적용된 단일 **LVM Volume Group**으로 구성하고, 그 내부에 용도별 논리 볼륨(LV)을 분리했습니다:
    - `/`(`root`, `ext4`): OS 및 핵심 시스템 파일
    - `/home`(`home`, `ext4`): 사용자 데이터 영역 분리 (디스크 가득 참으로 인한 시스템 장애 방지)
    - `/var/log`(`var_log`, `ext4`): 시스템 및 `sudo` 로그 격리 (로그 폭주 시 루트 파일시스템 보호)
    - `swap`(`swap`): 물리 메모리 부족 대비 가상 메모리 영역
- **사용자 및 그룹 관리 (User Management)**
  - 호스트명은 `hyunlee42`로 설정했습니다.
  - `root` 계정 외에 `hyunlee` 계정을 생성하고, 과제 요구사항에 따라 `user42` 및 `sudo` 그룹에 소속시켰습니다.
- **보안 정책 (Security Policies)**
  - **비밀번호 만료 정책** (`/etc/login.defs` & `chage`): 최대 사용 기간 `30일`(`PASS_MAX_DAYS`), 최소 변경 간격 `2일`(`PASS_MIN_DAYS`), 만료 경고 `7일 전`(`PASS_WARN_AGE`)을 설정하고 `root`와 `hyunlee` 계정에 모두 적용했습니다.
  - **비밀번호 복잡도 정책** (`/etc/security/pwquality.conf`): 최소 길이 `10자`(`minlen=10`), 대문자(`ucredit=-1`)·소문자(`lcredit=-1`)·숫자(`dcredit=-1`) 각 1자 이상 포함, 동일 문자 연속 최대 `3회`(`maxrepeat=3`), 사용자명 포함 금지(`usercheck=1`), 기존 비밀번호와 최소 `7자` 상이(`difok=7`), `root` 계정 강제 적용(`enforce_for_root`)을 구성했습니다.
  - **sudo 보안 정책** (`/etc/sudoers`): 비밀번호 재시도 `3회` 제한(`passwd_tries=3`), 실패 시 커스텀 메시지 출력(`badpass_message`), `requiretty` 활성화, `secure_path` 제한, 모든 입출력 로그의 `/var/log/sudo` 아카이빙(`log_input`, `log_output`, `iolog_dir`)을 설정했습니다.
- **설치 및 활성화된 서비스 (Services Installed)**
  - **OpenSSH (`sshd`)**: 기본 `22`번 대신 `4242` 포트만 사용하도록 변경하고, `PermitRootLogin no`로 `root` 직접 로그인을 차단했습니다. SELinux에도 `semanage port -a -t ssh_port_t -p tcp 4242`로 포트를 등록했습니다.
  - **firewalld**: 부팅 시 자동 실행되며, 기본 서비스(`ssh`, `cockpit`, `dhcpv6-client`)를 모두 제거하고 `4242/tcp` 포트만 허용했습니다.
  - **cron (`crond`)**: `/usr/local/sbin/monitoring.sh`를 부팅 시(`@reboot`) 및 매 `10분`(`*/10 * * * *`)마다 실행하여 `wall`을 통해 전체 터미널에 서버 상태를 브로드캐스트합니다.

### 3. 핵심 기술 비교 (Comparisons)

#### Debian vs Rocky Linux

| 비교 항목 | Debian | Rocky Linux |
| :--- | :--- | :--- |
| **기반 계열** | 독립 배포판 (Debian 계열) | RHEL(Red Hat Enterprise Linux) 1:1 바이너리 호환 |
| **패키지 관리** | `.deb` / `apt`, `aptitude`, `dpkg` | `.rpm` / `dnf`, `yum`, `rpm` |
| **기본 MAC(강제 접근 제어)** | **AppArmor** | **SELinux** |
| **기본 방화벽 도구** | **UFW** (Uncomplicated Firewall) | **firewalld** |
| **장점** | 설정이 직관적이고 가벼우며 커뮤니티 문서가 방대해 입문자에게 친화적임 | 엔터프라이즈 표준 보안(SELinux)이 기본 탑재되어 기업 서버 환경과 동일하며 장기 안정성이 뛰어남 |
| **단점** | 기본 보안 정책(AppArmor 경로 기반)이 SELinux보다 세밀함에서 차이가 있음 | SELinux 컨텍스트/포트 관리 등 초기 설정 난이도와 학습 곡선이 상대적으로 높음 |

#### AppArmor vs SELinux

| 비교 항목 | AppArmor (Application Armor) | SELinux (Security-Enhanced Linux) |
| :--- | :--- | :--- |
| **접근 제어 방식** | **경로 기반 (Path-based)** 강제 접근 제어 | **레이블/컨텍스트 기반 (Label/Type Enforcement)** 강제 접근 제어 |
| **적용 대상** | 개별 실행 파일(프로필이 등록된 애플리케이션) 중심 | 파일, 프로세스, 포트, 사용자 등 시스템의 모든 객체 |
| **설정 및 관리** | 텍스트 기반 파일 경로 규칙으로 비교적 이해와 수정이 쉬움 | 보안 컨텍스트(`user:role:type:level`)와 정책 모듈(`semanage`) 기반으로 정교하지만 복잡함 |
| **보안성 특징** | 심볼릭 링크나 파일 이름 변경 시 우회 가능성을 고려해야 함 | 파일 경로가 바뀌어도 inode에 부여된 보안 레이블이 유지되어 일관된 통제가 가능함 |

#### UFW vs firewalld

| 비교 항목 | UFW (Uncomplicated Firewall) | firewalld |
| :--- | :--- | :--- |
| **설계 목적** | `iptables`/`nftables`를 단순화한 직관적인 CLI 프론트엔드 | **Zone(영역)**과 **Service** 개념을 도입한 동적 방화벽 데몬 |
| **규칙 반영 방식** | 설정 변경 시 방화벽 규칙 전체를 다시 로드 | 기존 연결 세션을 끊지 않고 런타임(`runtime`)과 영구(`permanent`) 설정을 동적으로 분리·반영 |
| **주요 사용 환경** | Debian, Ubuntu 계열 | RHEL, Rocky Linux, Fedora, CentOS 계열 |
| **사용성** | `ufw allow 4242/tcp`처럼 명령이 매우 간결함 | `firewall-cmd --permanent --zone=public --add-port=4242/tcp`처럼 세밀한 영역별 제어가 가능함 |

#### VirtualBox vs UTM

| 비교 항목 | Oracle VirtualBox | UTM |
| :--- | :--- | :--- |
| **기반 하이퍼바이저** | 자체 크로스플랫폼 Type-2 하이퍼바이저 | **QEMU** 및 Apple `Hypervisor.framework` 기반 |
| **지원 플랫폼** | Windows, Linux, macOS ( 주로 x86/x64 호스트에 최적화) | **macOS / iOS 전용** (특히 Apple Silicon M1/M2/M3/M4 환경에 최적화) |
| **디스크 이미지 포맷** | `.vdi` (기본), `.vmdk`, `.vhd` | `.qcow2` (QEMU 표준 포맷) |
| **특징** | 스냅샷, 네트워크 어댑터(NAT/포트포워딩), 확장팩 등 데스크톱 가상화 기능이 풍부하고 범용성이 높음 | macOS 네이티브 UI로 가볍고, ARM 아키텍처 가상화뿐만 아니라 타 아키텍처(x86_64) 에뮬레이션도 지원함 |

---

## Instructions

### 1. 서버 설치 및 초기 세팅 전 과정 (Step-by-Step Setup)

<details>
<summary><b>클릭하여 전체 설치 및 세팅 과정 펼치기 / 접기 (Rocky Linux 10.2 Minimal)</b></summary>

#### 1.1 VirtualBox VM 생성 (Host)

| 항목 | 설정값 | 역할 및 설명 |
| :--- | :--- | :--- |
| **VM 이름 / OS** | `b2r` / Linux · Red Hat (64-bit) | 가상머신 식별 이름 및 RHEL 계열 커널 프로필 지정 |
| **시스템** | RAM `4096 MB` · vCPU `2` · EFI `끔` | VM 메모리/코어 할당 및 Legacy BIOS 부팅 모드 사용 |
| **저장소** | VDI (동적 할당) · `Rocky Linux 10.2 Minimal` ISO | 가상 디스크 생성 및 설치 이미지 마운트 |
| **네트워크** | 어댑터 1: `NAT` (일반 DHCP) | 호스트 네트워크를 통한 외부 통신 및 포트 포워딩 기반 제공 |
| **포트 포워딩** | `ssh` · `TCP` · Host `127.42.42.42:4242` → Guest `:4242` | 호스트의 `4242` 포트 접속을 게스트의 SSH(`4242`)로 연결 |

#### 1.2 Rocky Linux 설치 GUI (Guest)

| 항목 | 설정값 | 역할 및 설명 |
| :--- | :--- | :--- |
| **시간대 / 소프트웨어** | `Asia/Seoul` · `Minimal Install` | 한국 표준시 설정 및 GUI 없는 최소 패키지 설치 (과제 필수) |
| **시스템 / 네트워크** | Kdump `끔` · `enp0s3` 연결 켜기 · 호스트명 `hyunlee42` | 커널 덤프 메모리 예약 해제, 부팅 시 네트워크 자동 활성화, 호스트명 지정 |
| **계정 설정** | Root 암호 설정 · `hyunlee` 생성 (`sudo`, `user42` 추가) | 과제 요구사항인 `sudo` 및 `user42` 그룹 등록 |
| **기본 보안 유지** | `authselect local` / `pam_pwquality` · `SELinux Enforcing` · `sudo secure_path` | PAM 비밀번호 검증, SELinux 강제 보호, sudo 안전 경로 기본값 유지 |

#### 1.3 디스크 파티셔닝 (`Custom` · `GPT`)

| 구분 | 마운트 포인트 / 이름 | 파일시스템 / 장치 유형 | 역할 및 설명 |
| :--- | :--- | :--- | :--- |
| **Standard Partition** | *(없음)* | `BIOS Boot` | Legacy BIOS + GPT 디스크 환경에서 GRUB 부트로더 설치 영역 |
| **Standard Partition** | `/boot` | `ext4` | 부팅 커널 및 초기 램디스크 보관 (LUKS 복호화 전 접근을 위해 비암호화) |
| **Volume Group (LVM)** | VG (자동/기본) | `LVM` + **Encrypt (LUKS 켬)** | 나머지 전체 공간을 암호화된 단일 볼륨 그룹으로 묶어 동적 관리 |
| ↳ **Logical Volume** | `/` (`root`) | `ext4` | 루트 파일시스템 (OS 및 기본 시스템 파일 영역) |
| ↳ **Logical Volume** | `/home` (`home`) | `ext4` | 사용자 홈 디렉터리 분리 (사용자 데이터로 인한 루트 용량 고갈 방지) |
| ↳ **Logical Volume** | `/var/log` (`var_log`) | `ext4` | 시스템/sudo 로그 전용 파티션 분리 (로그 폭주로 인한 시스템 마비 방지) |
| ↳ **Logical Volume** | `swap` (`swap`) | `swap` | 물리 메모리(RAM) 부족 시 사용하는 가상 메모리 영역 |

> **부팅 진행**: `Begin Installation` → `Reboot` → ISO 제거 → `LUKS 암호` 입력 → `hyunlee` 로그인

---

#### 1.4 호스트명 및 계정 확인

```bash
sudo hostnamectl set-hostname hyunlee42  # 시스템 호스트명을 hyunlee42로 설정
groups hyunlee                           # hyunlee 계정의 소속 그룹 목록 확인 (sudo, user42 포함 여부)
```

---

#### 1.5 비밀번호 정책 설정

**`/etc/login.defs` 수정**:

```bash
sudoedit /etc/login.defs                 # 신규 생성 계정에 적용될 기본 비밀번호 만료 정책 편집
```

```text
PASS_MAX_DAYS 30                         # 비밀번호 최대 사용 기간 (30일마다 변경 필요)
PASS_MIN_DAYS 2                          # 비밀번호 변경 후 다시 변경하기까지 최소 대기 일수 (2일)
PASS_WARN_AGE 7                          # 비밀번호 만료 전 경고 메시지 출력 시작 시점 (만료 7일 전)
```

**`/etc/security/pwquality.conf` 수정**:

```bash
sudoedit /etc/security/pwquality.conf    # PAM(pam_pwquality) 비밀번호 복잡도 규칙 편집
```

```ini
difok = 7                                # 기존 비밀번호와 달라야 하는 최소 문자 수
minlen = 10                              # 비밀번호 최소 길이 (10자 이상)
dcredit = -1                             # 숫자(Digit) 최소 1자 이상 필수 포함
ucredit = -1                             # 대문자(Uppercase) 최소 1자 이상 필수 포함
lcredit = -1                             # 소문자(Lowercase) 최소 1자 이상 필수 포함
maxrepeat = 3                            # 동일한 문자의 연속 사용 최대 허용 횟수 (3회까지 허용)
usercheck = 1                            # 비밀번호 내에 사용자 계정명(username) 포함 금지
enforcing = 1                            # 규칙 위반 시 경고만 하지 않고 비밀번호 설정을 강제 거부
enforce_for_root                         # root 계정의 비밀번호를 변경할 때도 위 복잡도 정책을 강제 적용
```

**기존 계정 만료 주기 적용**:

```bash
sudo chage -M 30 -m 2 -W 7 root          # 이미 생성된 root 계정에 최대(30일)·최소(2일)·경고(7일) 주기 적용
sudo chage -M 30 -m 2 -W 7 hyunlee       # 이미 생성된 hyunlee 계정에 최대(30일)·최소(2일)·경고(7일) 주기 적용
```

---

#### 1.6 `sudo` 설정

```bash
sudo visudo                              # 문법 검증 기능이 포함된 전용 편집기로 /etc/sudoers 수정
```

```text
Defaults passwd_tries=3                     # sudo 비밀번호 입력 최대 시도 횟수 제한 (3회)
Defaults badpass_message="Bad authentication" # sudo 비밀번호가 틀렸을 때 출력할 사용자 정의 경고 문구
Defaults requiretty                         # 보안을 위해 실제 터미널(TTY)에 연결된 세션에서만 sudo 실행 허용
Defaults log_input, log_output              # sudo로 실행한 명령어의 표준 입력(input)과 출력(output)을 모두 기록
Defaults iolog_dir="/var/log/sudo"          # 기록된 sudo 입출력 아카이브 로그를 저장할 디렉터리 경로
```

---

#### 1.7 SSH · SELinux · firewalld 설정

**`/etc/ssh/sshd_config` 수정**:

```bash
sudo vi /etc/ssh/sshd_config             # SSH 데몬 설정 파일 편집
```

```text
Port 4242                                # SSH 서비스 수신 포트를 기본 22번에서 4242번으로 변경
PermitRootLogin no                       # SSH를 통한 root 계정의 직접 원격 로그인 차단
```

**SELinux 포트 등록 및 방화벽 설정**:

```bash
sudo dnf install policycoreutils-python-utils                      # semanage 명령어 사용을 위한 SELinux 관리 도구 설치
sudo semanage port -a -t ssh_port_t -p tcp 4242                    # SELinux 정책에 TCP 4242 포트를 SSH 허용 포트로 추가
sudo systemctl enable --now firewalld                              # firewalld 방화벽을 부팅 시 자동 실행하도록 등록하고 즉시 시작
sudo firewall-cmd --permanent --add-port=4242/tcp    # 방화벽 public 존에 4242/tcp 포트를 영구 개방
sudo firewall-cmd --permanent --remove-service=ssh   # 기본 ssh 서비스(22/tcp) 포트 허용 규칙 영구 제거
sudo firewall-cmd --permanent --remove-service=cockpit       # 불필요한 기본 허용 서비스(cockpit 웹 콘솔) 영구 제거
sudo firewall-cmd --permanent --remove-service=dhcpv6-client # 불필요한 기본 허용 서비스(IPv6 DHCP) 영구 제거
sudo firewall-cmd --reload                                         # 영구(--permanent) 설정한 방화벽 규칙을 현재 런타임에 즉시 반영
sudo systemctl restart sshd                                        # 변경된 포트(4242)와 설정을 적용하기 위해 SSH 데몬 재시작
```

---

#### 1.8 `monitoring.sh` 작성 및 `root` Crontab 등록

```bash
vi monitoring.sh                         # 시스템 상태 수집 및 브로드캐스트 스크립트 작성
```

```bash
#!/bin/bash
{
    architecture=$(uname -a)                                              # 커널 및 OS 아키텍처 전체 정보 조회
    physical=$(lscpu -p=SOCKET | grep -v '^#' | sort -u | wc -l)          # 고유 물리 CPU 소켓 개수 계산
    virtual=$(lscpu -p=CPU | grep -v '^#' | wc -l)                        # 가상 CPU(vCPU) 코어 개수 계산

    printf '#Architecture: %s\n' "$architecture"                          # 아키텍처 출력
    printf '#CPU physical : %s\n' "$physical"                             # 물리 CPU 수 출력
    printf '#vCPU : %s\n' "$virtual"                                      # vCPU 수 출력

    LC_ALL=C free -m | awk '$1 == "Mem:" {printf "#Memory Usage: %s/%sMB (%.2f%%)\n", $3, $2, $3 / $2 * 100}'                       # RAM 사용량/전체용량(MB) 및 사용률(%) 계산
    LC_ALL=C df -m --total -x tmpfs -x devtmpfs | awk '$1 == "total" {printf "#Disk Usage: %s/%.0fGb (%.0f%%)\n", $3, $2 / 1024, $3 / $2 * 100}' # 임시 파일시스템을 제외한 전체 디스크 사용량(MB)/전체(GB) 및 비율(%) 계산

    LC_ALL=C vmstat 1 2 | awk 'END {printf "#CPU load: %.1f%%\n", 100 - $15}' # 1초 간격 2회 측정 후 유휴(id, $15) 비율을 빼서 현재 CPU 부하율 계산
    printf '#Last boot: %s\n' "$(uptime -s | cut -c 1-16)"                # 마지막 시스템 부팅 시각(YYYY-MM-DD HH:MM) 출력

    if lsblk -rn -o TYPE | grep -qx lvm; then                             # 블록 장치 중 lvm 타입이 존재하는지 확인
        printf '#LVM use: yes\n'                                          # LVM 사용 중일 때 yes 출력
    else
        printf '#LVM use: no\n'                                           # LVM 미사용 시 no 출력
    fi
    printf '#Connections TCP : %s ESTABLISHED\n' "$(ss -Htn state established | wc -l)" # 현재 연결 수립(ESTABLISHED) 상태인 TCP 세션 수 집계

    users=$(who | awk '{print $1}' | sort -u | wc -l)                     # 현재 로그인한 고유 사용자 수 집계
    ip_address=$(ip -4 -o address show dev enp0s3 | awk '{print $4}' | cut -d / -f 1) # enp0s3 인터페이스의 IPv4 주소만 추출
    mac_address=$(cat /sys/class/net/enp0s3/address)                      # enp0s3 인터페이스의 MAC 주소 조회
    printf '#User log: %s\n' "$users"                                     # 로그인 사용자 수 출력
    printf '#Network: IP %s (%s)\n' "$ip_address" "$mac_address"          # IPv4 주소 및 MAC 주소 출력

    sudo_count=$(sudoreplay -d /var/log/sudo -l | wc -l)                  # /var/log/sudo에 기록된 sudo 실행 세션 로그 개수 집계
    printf '#Sudo : %s cmd\n' "$sudo_count"                               # 누적 sudo 명령어 실행 횟수 출력
} | wall                                                                  # 출력 결과를 전체 터미널에 일괄 브로드캐스트
```

```bash
sudo install -o root -g root -m 755 monitoring.sh /usr/local/sbin/monitoring.sh  # 소유자 root, 권한 755로 시스템 경로에 스크립트 설치
sudo systemctl enable --now crond                                                # cron 스케줄러 데몬 자동 시작 등록 및 즉시 실행
sudo crontab -e                                                                  # root 계정의 주기적 작업(crontab) 편집
```

```cron
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin  # cron 환경에서 lscpu, ss, sudoreplay 등을 찾도록 PATH 지정
*/10 * * * * /bin/bash /usr/local/sbin/monitoring.sh               # 매 10분마다 monitoring.sh 스크립트 자동 실행
@reboot /bin/bash /usr/local/sbin/monitoring.sh                    # 시스템 부팅 직후 monitoring.sh 스크립트 1회 실행
```

</details>

### 2. 디스크 서명(`signature.txt`) 확인 및 생성

제출 저장소 루트에는 가상머신 자체가 아닌 가상 디스크(`b2r.vdi`)의 **SHA-1 해시값**이 담긴 `signature.txt`와 `README.md`만 포함됩니다.

> **주의**: 가상머신을 부팅하면 디스크 파일이 변경되어 해시값이 달라집니다. 평가 전까지 VM을 켜지 않거나 백업 본을 유지해야 하며, 평가 시작 시 스냅샷이 존재해서는 안 됩니다.

```bash
# 1. VM 종료 상태에서 해시값만 추출해 signature.txt 생성 및 원본 디스크 백업 (최초 1회)
cd ~/goinfre/br2/b2r
sha1sum b2r.vdi | cut -d ' ' -f 1 > signature.txt
cp b2r.vdi b2r.vdi.bak

# 2. 평가 시 클론한 저장소 루트에서 signature.txt와 b2r.vdi 해시값을 diff로 비교 (무출력 시 일치)
diff <(sha1sum ~/goinfre/br2/b2r/b2r.vdi | cut -d ' ' -f 1) signature.txt

# 3. 평가 종료 후 다음 평가를 위해 원본 디스크로 복원
cp -f ~/goinfre/br2/b2r/b2r.vdi.bak ~/goinfre/br2/b2r/b2r.vdi
```

### 3. 가상머신 실행 및 SSH 접속

1. **VirtualBox**에서 `b2r` 가상머신을 시작합니다.
2. 부팅 과정에서 **LUKS 디스크 복호화 암호**를 입력합니다.
3. 부팅이 완료되면 호스트 터미널에서 포트 포워딩(`4242`)을 통해 SSH로 접속합니다:

```bash
# 일반 사용자(hyunlee)로 SSH 접속 (성공해야 함)
ssh -p 4242 hyunlee@127.42.42.42

# root 계정으로 SSH 접속 테스트 (차단되어야 함)
ssh -p 4242 root@127.42.42.42
```

### 4. 시스템 설정 검증 명령어 (Guest 내부)

```bash
# 1. OS 버전 및 호스트명 확인
hostnamectl

# 2. SELinux 작동 상태 확인 (enforcing)
sestatus

# 3. 사용자 소속 그룹 확인 (sudo, user42)
groups hyunlee

# 4. 디스크 파티션 및 LVM / LUKS 암호화 구조 확인
lsblk

# 5. 방화벽 및 SSH 포트 확인 (4242/tcp)
sudo firewall-cmd --list-all
ss -tunlp

# 6. 비밀번호 만료 주기 확인
sudo chage -l root
sudo chage -l hyunlee

# 7. sudo 아카이브 로그 확인
sudo sudoreplay -d /var/log/sudo -l
```

### 5. 모니터링 스크립트(`monitoring.sh`) 제어

- **수동 실행 테스트**:
  ```bash
  sudo /usr/local/sbin/monitoring.sh
  ```
- **스크립트 수정 없이 브로드캐스트 중지 (재부팅 후에도 유지) / 재개**:
  ```bash
  # cron 데몬 중지 및 부팅 자동 실행 해제 (또는 sudo crontab -e에서 주석 처리)
  sudo systemctl disable --now crond

  # cron 데몬 다시 활성화 및 시작
  sudo systemctl enable --now crond
  ```

---

## Resources

### 참고 문서 (References)
- [Rocky Linux 10 Official Documentation](https://docs.rockylinux.org/) — 설치, 네트워크, 시스템 관리 공식 가이드
- [Red Hat Enterprise Linux Security Hardening Guide](https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/) — SELinux, PAM(`pam_pwquality`), LUKS 암호화 및 `firewalld` 구성 레퍼런스
- [Sudoers Manual (`man sudoers`)](https://www.sudo.ws/docs/man/sudoers.man/) — `visudo` 옵션(`passwd_tries`, `badpass_message`, `requiretty`, `log_input`/`log_output`, `iolog_dir`, `secure_path`) 명세
- Linux Manual Pages: `man 8 lvm`, `man 8 cryptsetup`, `man 5 login.defs`, `man 5 pwquality.conf`, `man 1 chage`, `man 8 semanage-port`, `man 1 firewall-cmd`, `man 5 crontab`, `man 1 wall`

### AI 활용 내역 (AI Usage)
- **문서화 구조 정리 및 검토**: 설치 및 설정 절차를 요약한 가이드 문서(`speedrun.md`)와 과제 명세서(Chapter VI: Readme Requirements)의 필수 항목을 충족하는 `README.md`의 마크다운 표 및 섹션 구성을 정리하고 가독성을 다듬는 데 AI를 활용했습니다.
- **개념 비교 정리**: Debian vs Rocky Linux, AppArmor vs SELinux, UFW vs firewalld, VirtualBox vs UTM 간의 핵심 아키텍처 차이를 요약·검토하는 데 참고했습니다.
