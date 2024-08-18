void insertionsort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;

        }
        arr[j+1] = key;
    }
}

void buublesort(int *arr,int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1] ){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionsort(int *arr,int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
               
            }
        }
         swap(arr[i],arr[minIndex]);
    }
}


void merge(vector<int>&arr,int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){

        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int> &arr, int low, int high){

    if(low == high) return;
    int mid = (low + high)/2;

    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);

}


int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];
    int p = start;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[p]);
            p++;
        }
    }
    swap(arr[p], arr[end]);
    return p;
}

void quicksort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}

