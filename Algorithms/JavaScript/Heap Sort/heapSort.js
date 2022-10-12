function heapSort(arr) {
    var len = arr.length,
    end = len - 1;
    heapify(arr, len);
    while (end > 0) {
        swap(arr, end--, 0);
        siftDown(arr, 0, end);
    }
    return arr;
}

function heapify(arr, len) {
    var mid = Math.floor((len - 2) / 2);
    while (mid >= 0) {
        siftDown(arr, mid--, len - 1);
    }
}

function siftDown(arr, start, end) {
    var root = start,
    child, toSwap = arr[root];
    while (root * 2 + 1 <= end) {
        child = root * 2 + 1;
        if (child + 1 <= end && arr[child] < arr[child + 1]) {
            child++;
        }
        if (toSwap < arr[child]) {
            swap(arr, root, child);
            root = child;
        } else {
            return;
        }
    }
}

function swap(arr, i, j) {
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}