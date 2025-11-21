// This program calculates the number of Two-Wheelers (TW) and Four-Wheelers (FW)
// based on the total number of vehicles (V) and total number of wheels (W).

// Conditions:
// - Each TW has 2 wheels
// - Each FW has 4 wheels
// - V = TW + FW
// - W = (2 * TW) + (4 * FW)

// We use equations to find:
// FW = (W - 2 * V) / 2
// TW = V - FW

import java.util.*;

public class vehicles {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();   // Total vehicles
        int W = sc.nextInt();   // Total wheels

        // Validate input constraints
        if (W < 2 || W % 2 != 0 || V > W) {
            System.out.println("INVALID INPUT");
            return;
        }

        // Calculate number of four-wheelers
        int FW = (W - 2 * V) / 2;

        // Calculate number of two-wheelers
        int TW = V - FW;

        // Additional validation
        if (TW < 0 || FW < 0) {
            System.out.println("INVALID INPUT");
        } else {
            System.out.println("TW = " + TW + ", FW = " + FW);
        }
    }
}
