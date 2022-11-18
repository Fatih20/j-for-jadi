#include "../../ADT/Matriks/matriks.h"
#include "../../ADT/Simulator/simulator.h"
#include "../../ADT/Stack/stack.h"

/**
 * @brief Menunjukkan komponen situasi awal pengguna sebelum memasukkan command sesuai spek.
 *
 * @param cSimulator
 * @param peta
 * @param justUndo apakah command sebelumnya adalah undo
 * @param undoStack
 * @param showNotification
 */
void displayCondition(Simulator cSimulator, Matriks peta, boolean justUndo, Stack *undoStack, boolean showNotification);
