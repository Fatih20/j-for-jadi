#!/bin/bash
gcc mBInput.c tesMBInput.c ../MKInput/mKInput.c ../MCInput/mCInput.c ../Teks/teks.c ../ListDinTeks/ldinteks.c ../ListDinKar/ldinkar.c -o tesMBI -lm && ./tesMBI