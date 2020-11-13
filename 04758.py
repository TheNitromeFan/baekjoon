while True:
    entries = input().split()
    speed, weight, strength = float(entries[0]), int(entries[1]), int(entries[2])
    if speed == weight == strength == 0:
        break
    positions = []
    if speed <= 4.5 and weight >= 150 and strength >= 200:
        positions.append("Wide Receiver")
    if speed <= 6.0 and weight >= 300 and strength >= 500:
        positions.append("Lineman")
    if speed <= 5.0 and weight >= 200 and strength >= 300:
        positions.append("Quarterback")
    if not positions:
        positions.append("No positions")
    print(" ".join(positions))
