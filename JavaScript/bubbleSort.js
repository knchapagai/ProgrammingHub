function bubbleSort(arr) {
    var len = arr.length

    for (var i = 0; i < len; i++) {
        for (var j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                var temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            }
        }
    }
    return arr
}

bubbleSort([1,7,2,5,9,6,4,5,3,1,4,8])