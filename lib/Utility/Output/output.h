#include "../../ADT/Matriks/matriks.h"
#include "../../ADT/State/state.h"
#include "../../ADT/Stack/stack.h"

/**
 * @brief Menunjukkan komponen situasi awal pengguna sebelum memasukkan command sesuai spek.
 *
 * @param cState
 * @param peta
 * @param justUndo apakah command sebelumnya adalah undo
 * @param undoStack
 */
void displayCondition(State cState, Matriks peta, boolean justUndo, Stack *undoStack);
