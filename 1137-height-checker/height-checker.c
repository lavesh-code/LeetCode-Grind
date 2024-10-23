int c(const void* x, const void* y){
    return *(int*)x - *(int*)y;
}

int heightChecker(int* heights, int heightsSize) {
    int arr[heightsSize];
    memcpy(arr, heights, (sizeof(int) * heightsSize));
    qsort(heights, heightsSize, sizeof(int), c);
    int res = 0;
    for(int i = 0; i < heightsSize; i++){
        if(arr[i] != heights[i]){
            res++;
        }
    }
    return res;
}