import java.util.Random;

/**
 * Solution to the 8 queens problem using a genetic algorithm.
 */
public class Queens {

	public static final int Generations = 10000;
	public static final int Queens = 8;
	public static final int Population = 25;
	public static final int CrossP = 80;
	public static final int MutationP = 50;

	private Random rand = new Random();

	public static void main(String[] args) {
		Queens q = new Queens();
		q.run();
	}

	public int run() {
		int gen[][] = new int[Population][Queens];
		for (int i = 0; i < Population; i++) {
			for (int j = 0; j < Queens; j++) {
				gen[i][j] = rand.nextInt(Queens);
			}
		}
		int costs[] = getCosts(gen);
		int minimum = getMin(costs);
		
		System.out.println("Esialgse populatsiooni hinnang> ");
		for (int i = 0; i < Population; i++) {
			System.out.print(costs[i] + " ");
		}
		System.out.println("\nEsialgse populatsiooni minimum> " + minimum);
		System.out.println();

		return solve(gen, minimum, 0);
	}

	private int solve(int[][] gn, int min, int g) {
		int minimum = min;
		int generation = g;
		int[][] gen = gn;
		while (generation <= Generations) {
			int[][] nextGen = crossing(gen);
			int[] nextCosts = getCosts(nextGen);
			
			int k = find(nextCosts, 0);
			if (k >= 0) {
				System.out.println("Lahendus leitud");
				System.out.println("Samm = " + generation);
				printx(nextGen[k]);
				return generation;
			}
			int nextMinimum = getMin(nextCosts);

			if (nextMinimum <= minimum) {
				System.out.println("Uue populatsiooni hinnangud>");
				for (int i = 0; i < Population; i++) {
					System.out.print(nextCosts[i] + " ");
				}
				System.out.println("\nUus minimum hinnang = " + nextMinimum);
				System.out.println();
				
				minimum = nextMinimum;
				gen = nextGen;
			}

			generation++;
		}
		System.out.println("Ei leidnud lahendust pärast " +Generations+ " sammmu.");
		return Generations;
	}

	private int find(int[] ar, int k) {
		for (int i = 0; i < ar.length; i++) {
			if (ar[i] == k)
				return i;
		}
		return -1;
	}

	private int[][] crossing(int[][] gen) {
		int[][] children = new int[Population][Queens];
		for (int i = 0; i < Population; i++) {
			System.arraycopy(gen[i], 0, children[i], 0, gen[i].length);
		}
		for (int i = 0; i < Population; i++) {
			if (CrossP >= rand.nextInt(101)) {
				children[i] = cross(gen);
			}
			if (MutationP >= rand.nextInt(101)) {
				children[i] = mutate(children[i]);
			}
		}
		return children;
	}

	private int[] mutate(int[] gen) {
		int j = rand.nextInt(Queens);
		int dir = rand.nextInt(2);

		if (dir > 0) {
			if (gen[j] + 1 == Queens) {
				gen[j] = 0;
			} else
				gen[j]++;
		} else {
			if (gen[j] - 1 < 0) {
				gen[j] = Queens - 1;
			} else
				gen[j]--;
		}

		return gen;
	}

	private int[] cross(int[][] gen) {
		int k = rand.nextInt(Queens);
		int i1 = rand.nextInt(Population);
		int i2 = rand.nextInt(Population);
		int[] c3 = new int[Queens];
		for (int i = 0; i < k; i++) {
			c3[i] = gen[i1][i];
		}
		for (int i = k; i < Queens; i++) {
			c3[i] = gen[i2][i];
		}
		return c3;
	}

	private int[] getCosts(int[][] gen) {
		int[] costs = new int[gen.length];
		for (int i = 0; i < costs.length; i++) {
			costs[i] = getCost(gen[i]);
		}
		return costs;
	}

	private int getMin(int[] ar) {
		int s = ar[0];
		for (int i = 1; i < ar.length; i++)
			s = Math.min(s, ar[i]);
		
		return s;
	}

	private int getCost(int[] ar) {
		int c = 0;
		for (int i = 0; i < Queens; i++) {
			for (int j = 0; j < Queens; j++) {
				if (i != j) {
					if (ar[i] == ar[j])
						c++;
					if (Math.abs(ar[i] - ar[j]) == Math.abs(i - j))
						c++;
				}
			}
		}
		return c;
	}

	private void printx(int[] ar) {
		for (int i = 0; i < ar.length; i++) {
			for (int j = 0; j < ar.length; j++) {
				if (ar[i] == j) {
					System.out.print("X ");
				} else {
					System.out.print("- ");
				}
			}
			System.out.println();
		}
	}

}
