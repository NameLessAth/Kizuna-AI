import matplotlib.pyplot as plt

y = list(map(int, input("Masukkan nilai y dipisahkan oleh koma (contoh: 1,2,3): ").split(',')))
x = list(range(1, len(y) + 1))

plt.plot(x, y, marker='o', linestyle='-', color='b')  

plt.xlabel("Jumlah Iterasi")
plt.ylabel("Value")
plt.title("Plot antara Jumlah Iterasi dan Value")

plt.show()
