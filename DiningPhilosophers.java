import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadLocalRandom;

public class DiningPhilosophers {
	static int n = 10; 
	static int philosophersNumber = 5;
	static Philosopher philosophers[] = new Philosopher[philosophersNumber];
	static Chopstick Chopsticks[] = new Chopstick[philosophersNumber];

	static class Chopstick
	{
		public Semaphore mutex = new Semaphore(1);
		void grab() {
			try {
				mutex.acquire();
			}
			catch (Exception e)
			{
				e.printStackTrace(System.out);
      		}
    	}

    	void release()
    	{
      		mutex.release();
    	}

    	boolean isFree()
    	{
  			return mutex.availablePermits() > 0;
    	}

 	}

	static class Philosopher extends Thread
	{

	    public int number;
	    public Chopstick leftChopstick;
	    public Chopstick rightChopstick;

	    Philosopher(int num, Chopstick left, Chopstick right)
	    {
	    	number = num;
	    	leftChopstick = left;
	    	rightChopstick = right;
	    }

	    public void run(){
	    	System.out.println("Philosopher " + number);
	      	
	      	while(n>0) 
	      	{
		      	if(leftChopstick.isFree() && rightChopstick.isFree())
		      	{
			        leftChopstick.grab();
			        System.out.println("Philosopher " + number + " grabs left Chopstick.");
			        rightChopstick.grab();
			        System.out.println("Philosopher " + number + " grabs right Chopstick.");
			        eat();
			        leftChopstick.release();
			        System.out.println("Philosopher " + number + " releases left Chopstick.");
			        rightChopstick.release();
			        System.out.println("Philosopher " + number + " releases right Chopstick.");
			    }
			    else
			    {
			    	try
			    	{
			    		int sleepTime = ThreadLocalRandom.current().nextInt(0, 1000);
			    		System.out.println("Philosopher "+number+" thinking for "+ sleepTime);
			    		Thread.sleep(sleepTime);
			    	}
			    	catch(Exception e)
			    	{
			    		e.printStackTrace(System.out);
			    	}
			    }
			    n--;
	    	}
	    }

	    void eat()
	    {
	    	try
	    	{
		        int sleepTime = ThreadLocalRandom.current().nextInt(0, 1000);
		        System.out.println("Philosopher " +number+ " eats for " + sleepTime);
		        Thread.sleep(sleepTime);
	    	}
	    	catch (Exception e)
	    	{
	        	e.printStackTrace(System.out);
	    	}
	    }

	}

	public static void main(String argv[])
	{
	    System.out.println("Dining philosophers problem.");

	    for (int i = 0; i < philosophersNumber; i++) {
	      Chopsticks[i] = new Chopstick();
	    }

	    for (int i = 0; i < philosophersNumber; i++) {
	      philosophers[i] = new Philosopher(i, Chopsticks[i], Chopsticks[(i + 1) % philosophersNumber]);
	      philosophers[i].start();
	    }

	    // while (true) {
	    //  	try 
	    //  	{
	    //     // sleep 1 sec
	    //     	Thread.sleep(1000);

	    //     // check for deadlock
	    //     	boolean deadlock = true;
	    //     	for (Fork f : forks) {
	    //       		if (f.isFree()) {
	    //         		deadlock = false;
	    //         		break;
	    //       		}
	    //     	}
	    //     	if (deadlock) {
	    //       		Thread.sleep(1000);
	    //       		System.out.println("There is a deadlock!");
	    //       		break;
	    //     	}
	    //   	}
	    //   	catch (Exception e) {
	    //     	e.printStackTrace(System.out);
	    //   	}
	    // }

	    //System.exit(0);
	}

}