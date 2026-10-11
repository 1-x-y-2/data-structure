bool GetElem(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length) return false;

    e = L.data[i - 1];

    return true;
}

int LocateElem(const SqList &L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i + 1;
    }

    return -1;
}