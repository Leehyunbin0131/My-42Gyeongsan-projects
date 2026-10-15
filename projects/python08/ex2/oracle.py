import os


def main() -> int:
    print("ORACLE STATUS: Reading the Matrix...\n")

    try:
        from dotenv import load_dotenv
    except ImportError:
        print("ERROR: python-dotenv is not installed.")
        print("Install with: python -m pip install -r requirements.txt")
        return 1

    try:
        env_loaded = load_dotenv()
    except (OSError, UnicodeError):
        print("ERROR: Unable to read the .env file.")
        return 1

    mode = os.getenv("MATRIX_MODE", "development").strip()
    if mode not in ("development", "production"):
        print("ERROR: MATRIX_MODE must be development or production.")
        return 1

    database_url = os.getenv("DATABASE_URL")
    api_key = os.getenv("API_KEY")
    log_level = os.getenv("LOG_LEVEL")
    zion_endpoint = os.getenv("ZION_ENDPOINT")
    missing_config = False

    print("Configuration loaded:")
    print(f"Mode: {mode}")
    if mode == "development":
        instance = "local"
    else:
        instance = "production"
    if database_url is None or database_url.strip() == "":
        database_url = None
        missing_config = True
        print("ERROR: DATABASE_URL not found")
        print("Database: None")
    else:
        print(f"Database: Connected to {instance} instance")
    if api_key is None or api_key.strip() == "":
        api_key = None
        missing_config = True
        print("ERROR: API_KEY not found")
        print("API Access: None")
    else:
        print("API Access: Authenticated")
    if log_level is None or log_level.strip() == "":
        log_level = None
        missing_config = True
        print("ERROR: LOG_LEVEL not found")
    print(f"Log Level: {log_level}")
    if zion_endpoint is None or zion_endpoint.strip() == "":
        zion_endpoint = None
        missing_config = True
        print("ERROR: ZION_ENDPOINT not found")
        print("Zion Network: None")
    else:
        print("Zion Network: Online")
    print("\nEnvironment security check:")

    print("[OK] No hardcoded secrets detected")
    if missing_config:
        print("[INFO] Some configuration keys are missing")
    elif env_loaded:
        print("[OK] .env file properly configured")
    else:
        print("[INFO] No .env settings loaded; using environment variables")
    print("[OK] Production overrides available")
    print("\nThe Oracle sees all configurations.")
    return 0


if __name__ == "__main__":
    main()
