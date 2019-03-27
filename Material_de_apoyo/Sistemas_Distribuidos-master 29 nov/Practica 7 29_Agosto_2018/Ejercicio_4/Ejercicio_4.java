import java.lang.Math;

public class PruebaRendimiento
{
    public static void main(String[] args)
     {
       
     	double i = 0;
		int max = 100000000;

		double seno;
		double coseno;
		double tangente;
		double logaritmo;
		double raizCuadrada;


		while(i < max){

			coseno = coseno + Math.cos(i);
			seno = seno + Math.sin(i);
			tangente = Math.tan(i);
			logaritmo = logaritmo + Math.log(i);
			raizCuadrada = raizCuadrada + Math.sqrt(i);

		i++;

	}

	System.out.printl("Valor del seno : " + seno );
	System.out.printl("Valor del coseno : " + coseno );
	System.out.printl("Valor del tangente : " + tangente );
	System.out.printl("Valor del logaritmo : " + logaritmo );
	System.out.printl("Valor del raizCuadrada : " +raizCuadrada );




    }
}