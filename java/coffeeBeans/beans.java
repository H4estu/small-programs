/* 
 * beans.java
 * Main file to compute amount of water to add in at each of the 3 pours 
 * based on the weight of beans given.
 *
 ************************* COMMANDS *************************
 * Compile: javac beans.java
 * Run: java beans
 ************************************************************
 */

import java.util.Scanner;

public class beans
{	
    public static void main (String[] args)
    {
       	Scanner keyboard = new Scanner(System.in);
	
	// Obtain weight of beans (grams)	
       	System.out.println("Enter weight of beans:");

       	double beansWeight = keyboard.nextDouble();

	// Initialize arrays to hold new and standard pour weights.
	double[] pourRatios = new double[3];
	double[] newPourWeights = new double[3];

	// Compute pour ratios for normal case
	pourRatios = computePourRatios();
	
	// Compute total water to use based on new bean weight
	double waterWeight = computeNewWaterWeight(beansWeight);
	System.out.println("Total water to use: " + waterWeight);

	// Compute pour ratios with new bean weight
	newPourWeights = computeNewPourWeights(pourRatios, waterWeight);

	// Print new water pour weights (g)
	System.out.println("New water pour weights");
	for (int i=0; i<=2; i++) {
	    System.out.println(Math.round(newPourWeights[i]));
	}
	
    }

    private static double[] computePourRatios() {
	/* Compute water pour ratio of normal with normal 42g beans and 
         * 700g water.
	 *     Pour# | Poured(g) | Total(g) | Ratio
	 *     ------------------------------------
         *       1   |    150     |  150    | 4.67
	 *       2   |    250     |  400    | 2.80
	 *       3   |    300     |  700    | 2.33
	 */
	double[] pRatios = new double[3];

	pRatios[0] = 700.0 / 150;  
	pRatios[1] = 700.0 / 250;
	pRatios[2] = 700.0 / 300;              

       	return pRatios;
    }

    private static double computeNewWaterWeight(double bw) {
	/* Use standard water weight of 700 g and standard bean weight of 
         * 42 g,  which is what the pour ratios are based on.
         */
	double waterToBeansRatio = 700.0 / 42;
	double waterWeightNew = waterToBeansRatio * bw;

	return waterWeightNew;
    }

    private static double[] computeNewPourWeights(double[] pr, double wwn) {
	double[] pNew = new double[3];
	
	pNew[0] = wwn / pr[0];
	pNew[1] = wwn / pr[1] + pNew[0];
	pNew[2] = wwn / pr[2] + pNew[1];

	return pNew;
    }
}
