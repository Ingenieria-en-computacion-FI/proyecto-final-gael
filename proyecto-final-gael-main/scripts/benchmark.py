import subprocess
import time
import pandas as pd
import os

executables = {
    "SIM": "./sim.exe",
    "RR": "./rr.exe",
    "SJF": "./sjf.exe"
}

sizes = [100, 500, 1000, 5000]
runs = 5  # 🔥 importante para promedio

results = []

os.makedirs("reports/csv", exist_ok=True)

for name, exe in executables.items():
    for size in sizes:

        times = []

        for _ in range(runs):
            start = time.perf_counter()

            subprocess.run([exe, str(size)], capture_output=True)

            end = time.perf_counter()
            times.append(end - start)

        avg_time = sum(times) / len(times)

        results.append({
            "algorithm": name,
            "size": size,
            "time_sec": avg_time
        })

df = pd.DataFrame(results)
df.to_csv("reports/csv/benchmark_all.csv", index=False)

print(df)