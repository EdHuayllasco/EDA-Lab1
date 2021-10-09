import java.util.Arrays;
import java.util.Scanner;
import java.nio.file.Paths;

public class AlgorithmComparison {
    public static void main(String args[]) { 

      int [] arr = new int[10000]; // para el vector de 10000 elementos
      //int [] arr = new int[50000]; // para el vector de 50000 elementos
      //int [] arr = new int[100000]; // para el vector de 100000 elementos
      //int [] arr = new int[150000]; // para el vector de 150000 elementos
      //int [] arr = new int[200000]; // para el vector de 200000 elementos
      //int [] arr = new int[250000]; // para el vector de 250000 elementos
      //int [] arr = new int[300000]; // para el vector de 300000 elementos
      //int [] arr = new int[400000]; // para el vector de 400000 elementos
      //int [] arr = new int[500000]; // para el vector de 500000 elementos
      //int [] arr = new int[600000]; // para el vector de 600000 elementos
      //int [] arr = new int[700000]; // para el vector de 700000 elementos
      //int [] arr = new int[800000]; // para el vector de 800000 elementos
      //int [] arr = new int[900000]; // para el vector de 900000 elementos
      //int [] arr = new int[1000000]; // para el vector de 1000000 elementos
      
      int i = 0;
      try (Scanner scan = new Scanner(Paths.get("txt/10000.txt"))) {
        while( scan.hasNextInt() ) {
          int num = scan.nextInt();
          arr[i] = num;
          i++;
          //System.out.println(num); // para mostrar los elementos descomentar
        }
        scan.close();
      } catch (Exception e) {
          System.out.println("Error: " + e.getMessage());
        }
        System.out.println("Tamaño del arreglo = " + arr.length);
        System.out.println("\nElementos ordenados: ");
        System.out.println("\nAlgoritmo de ordenamiento\tTiempo tomado(ms)");
        Arrays.sort(arr);
        compareSortingAlgorithms(arr);
    }

    private static void compareSortingAlgorithms(int arr[]) {

        printSortingTime(SortType.BUBBLE, arr);
        printSortingTime(SortType.HEAP, arr);
        printSortingTime(SortType.INSERTION, arr);
        printSortingTime(SortType.MERGE, arr);
        printSortingTime(SortType.QUICK, arr);
        printSortingTime(SortType.SELECTION, arr);
        printSortingTime(SortType.SHELL, arr);
    }

    private static void printSortingTime(SortType sortType, int[] arr) {

        int arr2[] = new int[arr.length];
        System.arraycopy(arr, 0, arr2, 0, arr.length);

        long startTime = System.nanoTime();

        switch (sortType) {
            case BUBBLE:
                BubbleSort.bubbleSort(arr2);
                break;
            case HEAP:
                HeapSort.heapSort(arr2);
                break;
            case INSERTION:
                InsertionSort.insertionSort(arr2);
                break;
            case MERGE:
                MergeSort.mergeSort(arr2, 0, arr2.length - 1);
                break;
            case QUICK:
                QuickSort.quickSort(arr2, 0, arr2.length - 1);
                break;
            case SELECTION:
                SelectionSort.selectionSort(arr2);
                break;
            case SHELL:
                ShellSort.shellSort(arr2);
                break;
        }

        long endTime = System.nanoTime();
        long duration = endTime - startTime;
        long durationMiliSeconds = (long) duration / 1000000;

        System.out.printf("%-17s %15d %n", sortType + "_SORT", durationMiliSeconds);
    }
}