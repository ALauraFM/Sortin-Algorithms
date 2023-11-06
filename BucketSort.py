import tkinter as tk

# Função para ordenar o array usando o Bucket Sort
def bucketSort():
    input_array = [float(x) for x in input_entry.get().split()]
    bucket = []

    for i in range(len(input_array)):
        bucket.append([])

    for j in input_array:
        index_b = int(10 * j)
        bucket[index_b].append(j)

    for i in range(len(input_array)):
        bucket[i] = sorted(bucket[i])

    k = 0
    for i in range(len(input_array)):
        for j in range(len(bucket[i])):
            input_array[k] = bucket[i][j]
            k += 1

    result_label.config(text="Sorted Array: " + " ".join(map(str, input_array)))

# Cria a janela principal
window = tk.Tk()
window.title("Bucket Sort")

# Cria os elementos da interface
input_label = tk.Label(window, text="Enter array (e.g., .42 .32 .33 .52 .37 .47 .51):")
input_entry = tk.Entry(window)
sort_button = tk.Button(window, text="Sort", command=bucketSort)
result_label = tk.Label(window, text="Sorted Array: ")

# Organiza os elementos na janela
input_label.pack()
input_entry.pack()
sort_button.pack()
result_label.pack()

# Inicia a janela principal
window.mainloop()
