import random

for i in range(10):

    process = {

        "pid": i,

        "burst": random.randint(1, 20),

        "memory": random.randint(10, 500)
    }

    print(process)
