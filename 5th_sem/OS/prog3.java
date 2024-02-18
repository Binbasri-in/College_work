// 3. write program to simulate the concept of dining philosopher problem using semaphore
import java.util.concurrent.Semaphore;

class philosopher implements Runnable {
    private Semaphore room;
    private Semaphore[] chopsticks;
    private int phil;

    public philosopher(Semaphore room, Semaphore[] chopsticks, int phil) {
        this.room = room;
        this.chopsticks = chopsticks;
        this.phil = phil;
    }
    
    public void run() {
        try {
            room.acquire();
            System.out.println("Philosopher " + phil + " enters the room.");
            chopsticks[phil].acquire();
            chopsticks[(phil + 1) % 5].acquire();
            System.out.println("Philosopher " + phil + " is eating.");
            Thread.sleep(2000);
            System.out.println("Philosopher " + phil + " has finished eating.");
            chopsticks[phil].release();
            chopsticks[(phil + 1) % 5].release();
            room.release();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class prog3 {
    public static void main(String[] args) {
        Semaphore room = new Semaphore(4);
        Semaphore[] chopsticks = new Semaphore[5];
        for (int i = 0; i < 5; i++) {
            chopsticks[i] = new Semaphore(1);
        }
        Thread[] philosophers = new Thread[5];
        for (int i = 0; i < 5; i++) {
            philosophers[i] = new Thread(new philosopher(room, chopsticks, i));
            philosophers[i].start();
        }

        for (int i = 0; i < 5; i++) {
            try {
                philosophers[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

//***(It can be random so this is just an example output.)***
// Output:
// Philosopher 0 enters the room.
// Philosopher 1 enters the room.
// Philosopher 2 enters the room.
// Philosopher 3 enters the room.
// Philosopher 4 enters the room.
// Philosopher 0 is eating.
// Philosopher 1 is eating.
// Philosopher 2 is eating.
// Philosopher 3 is eating.
// Philosopher 4 is eating.
// Philosopher 0 has finished eating.
// Philosopher 1 has finished eating.
// Philosopher 2 has finished eating.
// Philosopher 3 has finished eating.
// Philosopher 4 has finished eating.
