// Main.cpp

#include "MemoryManager.h"

int main() {
    // Creamos un objeto MemoryManager y lo inicializamos con 1000 bytes de memoria.
    MemoryManager memMgr;
    memMgr.init(1000);

    // Creamos un bloque de memoria de 100 bytes.
    int blockId = memMgr.create(100);
    if (blockId >= 0) {
        std::cout << "Bloque de memoria creado en la posición: " << blockId << std::endl;

        // Establecemos un valor en ese bloque.
        memMgr.set(blockId, 42);

        // Obtenemos el valor de ese bloque.
        int value;
        memMgr.get(blockId, value);
        std::cout << "Valor del bloque: " << value << std::endl;

        // Aumentamos el conteo de referencias.
        memMgr.increaseRefCount(blockId);
        std::cout << "Aumentado el contador de referencias del bloque " << blockId << std::endl;

        // Imprimimos el dump de la memoria.
        memMgr.printDump();
    }

    return 0;
}

