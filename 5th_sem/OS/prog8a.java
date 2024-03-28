// 8. Write a program to simulate page replacement algorithms 
// a)FIFO

import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;

class main{
    public static void main(String args[]){
        int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
        int capacity = 4;

        HashSet<Integer> s = new HashSet<>(capacity);
        Queue<Integer> indexes = new LinkedList<>();

        int page_faults = 0;
        for (int i = 0; i < pages.length; i++){
            if (s.size() < capacity){
                if (!s.contains(pages[i])){
                    s.add(pages[i]);
                    indexes.add(pages[i]);
                    page_faults++;
                }
            } else {
                if (!s.contains(pages[i])){
                    int val = indexes.peek();
                    indexes.poll();
                    s.remove(val);

                    s.add(pages[i]);
                    indexes.add(pages[i]);
                    page_faults++;
                }
            }
        }
        System.out.println(page_faults);
    }
}

// output
// 7
