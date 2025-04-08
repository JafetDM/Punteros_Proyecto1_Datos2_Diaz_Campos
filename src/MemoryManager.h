// MemoryManager.h

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <iostream>
#include <vector>
#include <string>

class MemoryManager {
private:
    char* memory; // Bloque de memoria que vamos a administrar.
    unsigned long size; // Tamaño total de la memoria.
    std::vector<int> refCount; // Conteo de referencias por bloque de memoria.

public:
    // Constructor
    MemoryManager();

    // Destructor
    ~MemoryManager();

    // Inicializa el bloque de memoria.
    void init(unsigned long size);

    // Crea un bloque de memoria de un tamaño específico y lo marca como disponible.
    int create(unsigned long size);

    // Asigna un valor al bloque de memoria.
    void set(int id, int value);

    // Obtiene el valor de un bloque de memoria.
    void get(int id, int& value);

    // Incrementa el contador de referencias de un bloque de memoria.
    void increaseRefCount(int id);

    // Decrementa el contador de referencias de un bloque de memoria.
    void decreaseRefCount(int id);

    // Imprime el estado de la memoria (simula el dump).
    void printDump();
};

#endif // MEMORY_MANAGER_H
