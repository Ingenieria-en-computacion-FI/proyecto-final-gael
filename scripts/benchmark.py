import subprocess
import time
import pandas as pd

results = []

sizes = [100, 500, 1000, 5000]

for size in sizes:
    start = time.time()

    subprocess.run([
        "./bin/main",
        str(size)
    ])

    end = time.time()

    results.append({
        "size": size,
        "time": end - start
    })

pd.DataFrame(results).to_csv(
    "reports/csv/benchmark.csv",
    index=False
)
