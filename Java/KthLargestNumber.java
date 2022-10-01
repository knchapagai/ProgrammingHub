 public int max()
    {
        if(isEmpty())
        {
            throw new IllegalStateException();
        }
        return item[0];
    }
    public int KthLargesElement(int[] arr,int key)
    {
        if(key<1 || key>arr.length){
            throw new IllegalArgumentException();
        }
        var heap=new Main();
        for(int number:arr) {
            heap.insert(number);
        }
        for(int i=0;i<key-1;i++)
        {
            heap.remove();
        }
        return heap.max();
    }
