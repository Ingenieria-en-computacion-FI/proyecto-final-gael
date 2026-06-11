import subprocess
import time
import pandas as pd
import matplotlib.pyplot as plt
import os

executables = {
    "SIM": "./sim.exe",
    "RR": "./rr.exe",
    "SJF": "./sjf.exe"
}

sizes = [100, 500, 1000, 5000]
runs = 5

results = []

os.makedirs("reports/csv", exist_ok=True)
os.makedirs("reports/graphs", exist_ok=True)

for name, exe in executables.items():

    for size in sizes:

        times = []

        for _ in range(runs):

            start = time.perf_counter()

            subprocess.run(
                [exe, str(size)],
                capture_output=True
            )

            end = time.perf_counter()

            times.append(end - start)

        avg_time = sum(times) / len(times)

        results.append({
            "algorithm": name,
            "size": size,
            "time_sec": avg_time
        })

df = pd.DataFrame(results)

df.to_csv(
    "reports/csv/benchmark_all.csv",
    index=False
)

print(df)

# ---------- GRAFICA ----------

for algorithm in df["algorithm"].unique():

    subset = df[df["algorithm"] == algorithm]

    plt.plot(
        subset["size"],
        subset["time_sec"],
        marker="o",
        label=algorithm
    )

plt.xlabel("Tamaño de prueba")
plt.ylabel("Tiempo promedio (s)")
plt.title("Benchmark del Simulador de Sistema Operativo")
plt.legend()
plt.grid(True)

plt.savefig(
    "reports/graphs/benchmark.png"
)

plt.show()