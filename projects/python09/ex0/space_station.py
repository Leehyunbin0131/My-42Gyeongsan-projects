from pydantic import BaseModel, Field, ValidationError
from datetime import datetime


class SpaceStation(BaseModel):
    # Field로 문자열 길이와 수치 범위를 제한해 생성 시 검증한다.
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


def main() -> None:
    print("Space Station Data Validation")

    print("========================================")
    print("Valid station created:")
    try:
        station = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            is_operational=True,
            last_maintenance=datetime(2026, 10, 20),
            notes="hello",
        )
        # 생성에 성공한 경우에만 station의 정보에 접근한다.
        print(f"ID: {station.station_id}")
        print(f"Name: {station.name}")
        print(f"Crew: {station.crew_size} people")
        print(f"Power: {station.power_level:.1f}%")
        print(f"Oxygen: {station.oxygen_level:.1f}%")
        if station.is_operational:
            print("Status: Operational")
        else:
            print("Status: No Operational")
        print(f"Last maintenance: {station.last_maintenance}")
        print(f"Notes: {station.notes}")
    except ValidationError as error:
        print(error)

    print("\n\n========================================")
    print("Expected validation error:")
    # 승무원 정원인 20명을 초과해 검증 오류를 확인한다.
    try:
        station = SpaceStation(
            station_id="ISS001",
            name="ISS",
            crew_size=30,
            power_level=95.0,
            oxygen_level=98.0,
            is_operational=True,
            last_maintenance=datetime(2026, 10, 20),
            notes=None,
        )
    except ValidationError as error:
        print(error)


if __name__ == "__main__":
    main()
