from datetime import datetime
from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    # 개별 필드 검증이 끝난 뒤, 필드 간 관계를 검사한다.
    @model_validator(mode="after")
    def validate_contact(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")

        if (self.contact_type == ContactType.PHYSICAL
                and not self.is_verified):
            raise ValueError("Physical contact must be verified")

        if (self.contact_type == ContactType.TELEPATHIC
                and self.witness_count < 3):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )

        # 정확히 7.0인 경우는 제외하고, 이를 초과할 때만 메시지를 요구한다.
        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError(
                "Signal strength above 7.0 requires a message"
            )

        return self


def main() -> None:
    print("=== Valid Contact ===")
    try:
        contact = AlienContact(
            contact_id="AC001",
            timestamp=datetime.now(),
            location="Seoul",
            contact_type=ContactType.RADIO,
            signal_strength=8.5,
            duration_minutes=10,
            witness_count=2,
            message_received="Hello, Earth!",
            is_verified=True,
        )
        print(f"Contact ID: {contact.contact_id}")
        print(f"Type: {contact.contact_type.value}")
        print(f"Location: {contact.location}")
        print(f"Signal: {contact.signal_strength}")
        print(f"Message: {contact.message_received}")
    except ValidationError as error:
        print(error)

    print("\n=== Invalid Contact ===")
    # 확인되지 않은 물리 접촉 보고서를 만들어 검증 오류를 확인한다.
    try:
        AlienContact(
            contact_id="AC002",
            timestamp=datetime.now(),
            location="Busan",
            contact_type=ContactType.PHYSICAL,
            signal_strength=5.0,
            duration_minutes=15,
            witness_count=1,
            is_verified=False,
        )
    except ValidationError as error:
        print(error)


if __name__ == "__main__":
    main()
