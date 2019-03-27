import java.lang.Math;

public class Ejercicio_4 {

    public static void main(String[] args)
     {
       
     	double i = 0;
		int max = 100000000;

		double seno =0;
		double coseno = 0;
		double tangente =0;
		double logaritmo =0;
		double raizCuadrada =0;


		while(i < max){

			coseno = coseno + Math.cos(i);
			seno = seno + Math.sin(i);
			tangente = Math.tan(i);
			logaritmo = logaritmo + Math.log(i);
			raizCuadrada = raizCuadrada + Math.sqrt(i);

		i++;

	}

	System.out.println("Valor del seno : " + seno );
	System.out.println("Valor del coseno : " + coseno );
	System.out.println("Valor del tangente : " + tangente );
	System.out.println("Valor del logaritmo : " + logaritmo );
	System.out.println("Valor del raizCuadrada : " +raizCuadrada );




    }
}
