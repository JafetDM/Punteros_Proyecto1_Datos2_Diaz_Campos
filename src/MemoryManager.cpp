// MemoryManager.cpp

#include "MemoryManager.h"

MemoryManager::MemoryManager() : memory(nullptr), size(0) {}

MemoryManager::~MemoryManager() {
    delete[] memory; // Liberamos la memoria cuando el objeto es destruido.
}

void MemoryManager::init(unsigned long size) {
    this->size = size;
    memory = new char[size]; // Reservamos la memoria del tamaño solicitado.
    refCount.resize(size, 0); // Inicializamos el contador de referencias para cada bloque.
}

int MemoryManager::create(unsigned long blockSize) {
    // Buscamos un bloque libre (esto puede ser una asignación de espacio en el arreglo de memoria).
    for (int i = 0; i < size - blockSize; ++i) {
        if (refCount[i] == 0) {
            refCount[i] = 1; // Marcamos este bloque como en uso.
            return i; // Devolvemos el id del bloque.
        }
    }
    std::cerr << "No hay espacio suficiente para el bloque solicitado." << std::endl;
    return -1; // Si no hay espacio, devolvemos un valor negativo.
}

void MemoryManager::set(int id, int value) {
    if (id < 0 || id >= size) {
        std::cerr << "ID fuera de rango." << std::endl;
        return;
    }
    memory[id] = value; // Establecemos el valor en la posición de memoria correspondiente.
}

void MemoryManager::get(int id, int& value) {
    if (id < 0 || id >= size) {
        std::cerr << "ID fuera de rango." << std::endl;
        return;
    }
    value = memory[id]; // Obtenemos el valor de la posición de memoria correspondiente.
}

void MemoryManager::increaseRefCount(int id) {
    if (id < 0 || id >= size) {
        std::cerr << "ID fuera de rango." << std::endl;
        return;
    }
    refCount[id]++; // Aumentamos el contador de referencias para el bloque.
}

void MemoryManager::decreaseRefCount(int id) {
    if (id < 0 || id >= size) {
        std::cerr << "ID fuera de rango." << std::endl;
        return;
    }
    if (refCount[id] > 0) {
        refCount[id]--; // Disminuimos el contador de referencias para el bloque.
    }

    // Si el contador de referencias llega a 0, liberamos el bloque.
    if (refCount[id] == 0) {
        // Esto puede implicar liberar la memoria.
    }
}

void MemoryManager::printDump() {
    // Imprimimos un estado simple de la memoria para probar.
    std::cout << "Estado de la memoria:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Bloque " << i << ": RefCount = " << refCount[i] << std::endl;
    }
}


