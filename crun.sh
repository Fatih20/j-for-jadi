#!/bin/bash
gcc main.c lib/Utility/Commands/commands.c lib/Utility/String/String.c lib/Utility/Loader/Loader.c lib/ADT/AksiLokasi/aksiLokasi.c lib/ADT/FoodQueue/foodQueue.c lib/ADT/ListDinKar/ldinkar.c lib/ADT/ListDinMakanan/ldinmakanan.c lib/ADT/ListDinTeks/ldinteks.c lib/ADT/ListStatMakanan/lstatmakanan.c lib/ADT/Makanan/makanan.c lib/ADT/Matriks/matriks.c lib/ADT/MBFile/mBFile.c lib/ADT/MCFile/mCFile.c lib/ADT/MCInput/mCInput.c lib/ADT/MKFile/mKFile.c lib/ADT/MKInput/mKInput.c lib/ADT/Point/Point.c lib/ADT/SetID/setID.c lib/ADT/Simulator/simulator.c lib/ADT/Stack/stack.c lib/ADT/State/state.c lib/ADT/Teks/teks.c lib/ADT/Tree/tree.c lib/ADT/Waktu/waktu.c  -o main -lm && ./main