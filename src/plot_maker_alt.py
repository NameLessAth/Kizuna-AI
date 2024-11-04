import matplotlib.pyplot as plt

y = list(map(float, input("Masukkan nilai y dipisahkan oleh koma (contoh: 1,2,3): ").split(',')))
x = list(range(1, len(y) + 1))

plt.plot(x, y, marker='o', linestyle='-', color='b')  

plt.xlabel("Jumlah Iterasi")
plt.ylabel("exp(deltaE/T)")
plt.title("Plot antara Jumlah Iterasi dan exp(deltaE/T)")

plt.show()
