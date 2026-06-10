import pandas as pd
import matplotlib.pyplot as plt
import os

file_path = "reports/csv/benchmark_all.csv"

if not os.path.exists(file_path):
    print("No existe el CSV")
    exit()

df = pd.read_csv(file_path)

plt.figure(figsize=(10, 6))

for algo in df["algorithm"].unique():
    subset = df[df["algorithm"] == algo].sort_values("size")

    plt.plot(
        subset["size"],
        subset["time_sec"],
        marker="o",
        linewidth=2,
        label=algo
    )

plt.xlabel("Número de procesos (n)")
plt.ylabel("Tiempo promedio de ejecución (s)")
plt.title("Comparación de algoritmos de planificación CPU")
plt.grid(True)
plt.legend()

plt.tight_layout()

os.makedirs("reports/img", exist_ok=True)
plt.savefig("reports/img/benchmark.png", dpi=300)

plt.show()