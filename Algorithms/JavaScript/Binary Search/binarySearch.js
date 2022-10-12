function binarySearch(arr, key) {
    var left = 0;
    var right = arr.length - 1;
    while (left <= right) {
        var mid = Math.floor((left + right) / 2);
        if (arr[mid] === key) return mid;
        if (arr[mid] < key) left = mid + 1;
        if (arr[mid] > key) right = mid - 1;
    }
    return -1;
}