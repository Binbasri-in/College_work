// 2. write a program to simulate producer-consumer problem using Semaphore
import java.util.concurrent.Semaphore;

class Que {
    int item;
    static Semaphore semCon = new Semaphore(0);
    static Semaphore semProd = new Semaphore(1);

    void get() {
        try {
            semCon.acquire();
        } catch (InterruptedException e) {
            System.out.println("InterruptedException caught");
        }
        System.out.println("Consumer consumed item: " + item);
        semProd.release();
    }

    void put(int item) {
        try {
            semProd.acquire();
        } catch (InterruptedException e) {
            System.out.println("InterruptedException caught");
        }
        this.item = item;
        System.out.println("Producer produced item: " + item);
        semCon.release();
    }
}

class Producer implements Runnable {
    Que q;

    Producer(Que q) {
        this.q = q;
        new Thread(this, "Producer").start();
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            q.put(i);
        }
    }
}

class Consumer implements Runnable {
    Que q;

    Consumer(Que q) {
        this.q = q;
        new Thread(this, "Consumer").start();
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            q.get();
        }
    }
}

class prog2 {
    public static void main(String args[]) {
        Que q = new Que();
        new Producer(q);
        new Consumer(q);
    }
}

// Output:
// Producer produced item: 0
// Consumer consumed item: 0
// Producer produced item: 1
// Consumer consumed item: 1
// Producer produced item: 2
// Consumer consumed item: 2
// Producer produced item: 3
// Consumer consumed item: 3
// Producer produced item: 4
// Consumer consumed item: 4
