import java.util.Random;


public class HolaMundo {
    public static void main(String[] args){
        String cadenota ="";
        String cRand;
        int n =(int)Math.pow(26,3);
        int caracter;
        Random rnd = new Random();

        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                caracter =(char)(rnd.nextInt(26) + 65);
                cadenota +=(char) caracter;
            }
            cadenota+=" ";
        }
        //System.out.println(cadenota);
        
        int buscar = 0; /* Contador de las veces que aparece la palabra IPN */
        int pos; /* Variable que guarda la posición en la que se encontro la palabra IPN */
        for (int a = 0; a < n; a ++) {
            pos = cadenota.indexOf("IPN", a);
                if(pos != -1) {
                    buscar ++;
                a = pos;
                }
        }
        System.out.println("BUscar IPN: " +buscar);
    } 
}
