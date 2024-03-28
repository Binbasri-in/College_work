//LRU(Least recently used)
import java.util.HashSet;
import java.util.HashMap;
import java.util.Iterator;

class prog8b {
    public static void main(String args[]) {
        int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
        int capacity = 4;

        HashSet<Integer> s = new HashSet<>(capacity);
        HashMap<Integer, Integer> indexes = new HashMap<>();
        int page_faults = 0;
        for (int i = 0; i < pages.length; i++) {
            if (s.size() < capacity) {
                if (!s.contains(pages[i])) {
                    page_faults++;
                    s.add(pages[i]);
                }
            } else {
                if (!s.contains(pages[i])) {
                    int lre = Integer.MAX_VALUE;
                    int val = Integer.MIN_VALUE;
                    Iterator<Integer> itr = s.iterator();
                    while (itr.hasNext()) {
                        int temp = itr.next();

                        if (indexes.get(temp) < lre) {
                            lre = indexes.get(temp);
                            val = temp;
                        }
                    }
                    s.remove(val);
                    indexes.remove(val);
                    s.add(pages[i]);
                    page_faults++;
                }
            }
            indexes.put(pages[i], i);
        }

        System.out.println(page_faults);
    }
}
