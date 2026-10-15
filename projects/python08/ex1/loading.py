import importlib

libraries: list[tuple[str, str]] = [
    ("pandas", "Data manipulation ready"),
    ("numpy", "Numerical computation ready"),
    ("matplotlib", "Visualization ready"),
]


def check_dependencies() -> bool:
    missing = False
    for name, text in libraries:
        try:
            module = importlib.import_module(name)
        except ImportError:
            missing = True
            print(
                f"[MISS] {name} (Install with: python -m pip install {name})"
            )
        else:
            version = getattr(module, "__version__", "unknown")
            print(f"[OK] {name} ({version}) - {text}")
    return missing


def main() -> int:
    print("LOADING STATUS: Loading programs...\n")
    print("Checking dependencies:")

    if check_dependencies():
        print("\nInstall the dependencies in your virtual environment:")
        print("pip: python -m pip install -r requirements.txt")
        print("Poetry: poetry install")
        print("Then run this program again.")
        return 1

    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt

    print("\nAnalyzing Matrix data...")
    values = np.random.randn(1000)
    print(f"Processing {values.size} data points...")
    df = pd.DataFrame({"values": values})
    print("Generating visualization...")
    plt.hist(df["values"])
    plt.savefig("matrix_analysis.png")
    plt.close()
    print("\nAnalysis complete!")
    print("Results saved to: matrix_analysis.png")
    return 0


if __name__ == "__main__":
    main()
