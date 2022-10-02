//Link of the question : https://leetcode.com/problems/the-latest-time-to-catch-a-bus/

class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(passengers);
        Arrays.sort(buses);
        if(passengers[0] > buses[buses.length - 1]) return buses[buses.length - 1];
        int result = passengers[0] - 1;
        int i = 0, j = 0;
        while(i < buses.length){
            int occupiedSeats = 0;
            while(occupiedSeats < capacity && j < passengers.length && passengers[j] <= buses[i]){
                if(j > 0 && passengers[j] - passengers[j-1] != 1){
                    result = passengers[j] - 1;
                }
                j++;
                occupiedSeats++;
            }
            if(j - 1 > -1 && occupiedSeats < capacity && buses[i] != passengers[j-1]){
                result = buses[i];
            }
            i++;
        }
        return result;
    }
}