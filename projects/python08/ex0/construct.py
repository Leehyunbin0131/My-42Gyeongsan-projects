import sys
import os
import site

if __name__ == "__main__":
    if sys.prefix == sys.base_prefix:
        print("")
        print("MATRIX STATUS: You're still plugged in")
        print("")
        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected")
        print("")
        print(
            "WARNING: You're in the global environment!\n"
            "The machines can see everything you install.\n"
            "\n"
            "To enter the construct, run:\n"
            "python -m venv matrix_env\n"
            "source matrix_env/bin/activate # On Unix\n"
            "matrix_env\\Scripts\\activate # On Windows"
        )
        print("")
        print("Then run this program again.")
    else:
        print("MATRIX STATUS: Welcome to the construct")
        print("")
        # 현재 실행 중인 Python 실행 파일 경로
        print(f"Current Python: {sys.executable}")
        # 활성 가상환경 이름
        print(f"Virtual Environment: {os.path.basename(sys.prefix)}")
        # 가상환경 폴더의 전체 경로
        print(f"Environment Path: {sys.prefix}")
        print("")
        print(
            "SUCCESS: You're in an isolated environment!\n"
            "Safe to install packages without affecting\n"
            "the global system."
        )
        print("")
        print("Package installation path:")
        # 현재 환경의 패키지 설치 경로
        for path in site.getsitepackages():
            print(path)
