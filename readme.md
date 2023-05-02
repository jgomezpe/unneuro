<h2>UN_Neuro</h2>

<h3>Introducción</h3>
UN_Neuro es una herramienta que facilita el diseño, entrenamiento y simulación de redes neuronales, está hecha para MS-Windows 3.1.

Fue desarrollada en la Universidad Nacional de Colombia en los años 1992-1993, como proyecto de grado de Ingeniería de Sistemas. Cualquier inquietud o sugerencia puede ser dirigida a sus autores.

 Jonatan Gómez : jgomezpe@unal.edu.co
 Fabio González : fagonzalezo@unal.edu.co
	    


<h3>B. MANUAL DEL USUARIO</h3>

<h4>B.1 INTRODUCCION</h4>

UN-Neuro es un prototipo de herramienta para el diseño,
entrenamiento y simulación de redes neuronales.

<h5>B.1.1 Como Instalar UN-Neuro</h5>
El disco flexible con UN-Neuro contiene un programa ejecutable
que instala UN-Neuro, si la unidad donde se encuentra el disco
flexible, corresponde a la unidad A:, digite ' win A:\UNNEURO '.
Esto activará un programa de instalación.

<h5>B.1.2 Requerimientos de hardware y software</h5>
<ul>
<li>Para trabajar con UN-Neuro debe tener MicroSoft Windows 3.1 instalado en su computador.</li>
<li>2 Megabytes de memoria principal (Preferiblemente 4 Megabytes)</li>
<li>3 Megabyte en disco duro.</li>
<li>Se recomienda el uso de una pantalla a color.</li>
<li>Es indispensable el uso de un ratón.</li>
<li>Se recomienda el uso de un coprocesador matemático y un procesador 80386 o superior.</li>
</ul>

<h5>B.1.3 Uso de UN-Neuro</h5>
Para trabajar con UN-Neuro usted debe conocer cómo trabajar en Windows, si no ha trabajado en Windows consulte la guía del usuario Windows.

UN-Neuro al instalar genera un grupo Windows llamado UN-Neuro, presione rápidamente dos veces el botón izquierdo del ratón en el grupo UN-Neuro, y aparecerá la ventana mostrada en la ilustración 1.

En esta ventana aparecen tres íconos con los nombres UN-NeuroEditor, UN-NeuroEntrenador, UN-NeuroSimulador.

UN-NeuroEditor es el módulo de edición y diseño gráfico de redes neuronales.

UN-NeuroEntrenador es el módulo de entrenamiento de redes neuronales.

UN-NeuroSimulador es el módulo de simulación de redes neuronales.

Para entrar a cada modulo presione rápidamente dos veces el botón
izquierdo del ratón en el ícono del módulo.

<h5>B.1.4 Pasos para la realización de una aplicación de redes neuronales</h5>

La realización de una aplicación de redes neuronales implica la utilización de los tres módulos. Aunque no se tiene un orden
predefinido para el uso de los módulos, la secuencia típica de pasos para el empleo de los mismos es:

<ul>
<li>Diseñar y construir la red neuronal usando UN-NeuroEditor, guardándola en un archivo de disco.</li>

<li>Crear un archivo que contenga los patrones con los cuales se va a entrenar la red. Para esto se puede utilizar cualquier editor de texto (formato ASCII). Opcionalmente se puede crear otro archivo de patrones con el cual se realiza el cálculo del error de generalización durante el entrenamiento.</li>

<li>Utilizar UN-NeuroEntrenador, cargando la red generada por UN-NeuroEditor, así como los patrones creados en el paso anterior. Se debe especificar el algoritmo de entrenamiento. Después de terminado el entrenamiento se debe guardar la red en un archivo de disco.</li>

<li>Simular la red que fue almacenada en un archivo en disco en el paso anterior, utilizando UN-NeuroSimulador.</li>
</ul>

<h4>B.2 USANDO UN-NeuroEditor</h4>

UN-NeuroEditor es el módulo de edición y diseño de redes neuronales, en el cual se pueden tener a la vez varias redes en edición, cada una en una ventana diferente. Esta ventana tiene una barra de menús con los siguientes submenús:

<h5>B.2.1 Sumario de comandos</h5>

<b>Archivos:</b> Permite realizar las operaciones de disco disponibles en la aplicación como cargar, guardar, incluir, etc..

Las opciones del menú son:

 <b>Nueva:</b> Abre una ventana en blanco, para editar una red neuronal nueva (sin nombre). El efecto de este comando se puede apreciar en la ilustración 3.

 <b>Cargar:</b> Carga una red neuronal almacenada en un archivo en disco en una ventana con el nombre del archivo especificado. Primero seleccione esta opción con lo cual aparecerá una caja de diálogos en la que puede especificar el nombre del archivo. Al ejecutar este comando aparecerá una ventana conteniendo la red neuronal especificada, como lo muestra la ilustración 4.

 Guardar: Almacena la red neuronal de la ventana activa en un
          archivo en disco. Si la red neuronal que desea guardar
          no tiene nombre, la aplicación desplegará una caja de
          diálogos en la cual se debe especificar el nombre del
          archivo con el que se almacenara la red neuronal en
          disco.

 Guardar Como...:
          Almacena la red neuronal de la ventana activa en un
          archivo con el nombre que el usuario especifica,
          mediante una caja de diálogos.

 Incluir Red: 
          Incluye una red neuronal almacenada en un archivo en
          disco en la red neuronal actual, primero pregunta cual
          red quiere incluir mediante una caja de diálogos. Para
          incluir la red, primero se debe seleccionar esta
          opción, luego se debe seleccionar la opción Pegar del
          menú Edición y presionar el botón izquierdo del ratón
          en el lugar donde se quiere incluir la red.

Terminar: Cierra el modulo de edición, si alguna red neuronal no
          ha sido salvada pregunta si se desea salvar o no.

Edición:
Permite realizar la manipulación de bloques para realizar
operaciones de edición avanzadas como cortar, copiar, pegar,
etc..
Las opciones del menú son:

 Cortar:
          Elimina las neuronas y las conexiones relacionadas con
          éstas, que se encuentran en el bloque seleccionado y
          copia la subred neuronal contenida en el bloque a un
          buffer global. Para realizar esta operación, primero se
          debe seleccionar un bloque de neuronas de la red con la
          opción Seleccionar Bloque del menú de Edición. La
          subred almacenada en el buffer global puede ser copiada
          en cualquier red neuronal que se este editando al
          seleccionar la opción Pegar del menú de Edición y
          presionando el botón izquierdo del ratón en el lugar
          donde se quiere pegar.

 Copiar:
          Copia la subred neuronal contenida en el bloque
          seleccionado a un buffer global. Para realizar esta
          operación primero se debe seleccionar un bloque de
          neuronas de la red con la opción Seleccionar Bloque del
          menú de Edición. La subred almacenada en el buffer
          global puede ser copiada en cualquier red neuronal que
          se este editando al seleccionar la opción Pegar del
          menú de Edición y presionando el botón izquierdo del
          ratón en el lugar donde se quiere pegar.


 Pegar:
          Pega la subred contenida en un buffer global después de
          realizar cualquier operación de Copiar, Cortar o
          Incluir Red. Después de seleccionar esta opción, para
          pegar la red neuronal contenida en el buffer global, se
          debe presionar el botón izquierdo del ratón en el lugar
          donde se quiere pegar.

Seleccionar Bloque:
          Define un bloque de neuronas para realizar con ellas
          las operaciones de edición avanzada de bloques.
          Para seleccionar un bloque primero se debe escoger esta
          opción del menú, luego presionar el botón izquierdo del
          ratón sobre la primer coordenada del bloque, sin soltar
          el botón del ratón se arrastra el ratón hasta la
          segunda coordenada del bloque y se suelta el botón
          izquierdo del ratón. Después de seleccionar el bloque
          se pueden realizar las operaciones de Cortar, Copiar,
          Mover, y definir Bloques para conexión total. Se puede
          seleccionar una sola neurona presionando el botón
          izquierdo del ratón sobre la neurona y soltándolo
          inmediatamente.

Definir Bloque Origen:
          Determina que el bloque seleccionado de neuronas se
          considera como el bloque de origen para la conexión
          total entre dos bloques de neuronas. Para realizar esta
          operación debe seleccionarse previamente un bloque con
          la opción Seleccionar Bloque del menú de Edición.

Definir Bloque Destino:
          Determina que el bloque seleccionado de neuronas se
          considera como el bloque de destino para la conexión
          entre dos bloques de neuronas. El efecto es que de toda
          neurona del bloque origen sale una conexión a toda
          neurona del bloque destino. Para realizar esta
          operación debe seleccionarse previamente un bloque con
          la opción Seleccionar Bloque del menú de Edición. Para
          que esta opción tenga efecto, debe haberse definido
          previamente un bloque origen.

Copiar al Porta Papeles:
          Hace una copia gráfica de la red neuronal que se envía
          al Porta Papeles de Windows para ser llevado a otra
          aplicación que lea el Porta Papeles. 

Neurona:
Permite realizar las operaciones básicas sobre una neurona como
borrar, adicionar, modificar, etc..

Las opciones del menú son:

 Adicionar:
          Adiciona una neurona de entrada, oculta o de salida
          desplegando un submenú con las siguientes opciones
          Entrada, Oculta, Salida. Para adicionar una neurona a
          la red neuronal se debe elegir primero que tipo de
          neurona se va a adicionar seleccionándolo del submenú
          que aparece, y luego presionar el botón izquierdo del
          ratón en el lugar donde se desea adicionar.

 Borrar:
          Borra la neurona a seleccionar. Para borrar una neurona
          se debe seleccionar esta opción y luego presionar el
          botón izquierdo del ratón sobre la neurona a borrar.

 Modificar Bloque de:
          Modifica los atributos de las neuronas contenidas en el
          bloque seleccionado, mediante una caja de diálogos en
          la que se pueden especificar los atributos para este
          grupo de neuronas. Para realizar esta operación, se
          selecciona el bloque de neuronas a modificar con la
          opción de Seleccionar Bloque del menú de Edición, y se
          escoge esta opción.

 Consultar y Modificar:
          Muestra los atributos de la neurona que se seleccione,
          mediante una caja de diálogos. Para mostrar los
          atributos de la neurona se selecciona esta opción, y se
          presiona el botón izquierdo del ratón en la neurona a
          consultar. Esta caja de dialogos permite la
          modificación de los mismos.

 Fusionar:
          Fusiona dos neuronas en una. Para efectuar esta
          operación se escoge esta opción, se selecciona la
          neurona que se incluiría en otra presionando el botón
          izquierdo del ratón sobre ella, sin liberar el botón
          del ratón se ubica el ratón sobre la neurona que va a
          recibir la neurona ya seleccionada y se libera el botón
          izquierdo del ratón. Todas las conexiones de la primer
          neurona serán llevadas a la segunda neurona.

Conexión:
Permite realizar las operaciones básicas sobre una conexión como
borrar, adicionar, modificar, etc.

Las opciones del menú son:
 
 Adicionar:
          Adiciona una conexión entre dos neuronas. Primero se
          debe seleccionar la neurona de origen presionando el
          botón izquierdo del ratón sobre la neurona, sin liberar
          el botón se ubica el ratón sobre la neurona que va a
          ser la neurona destino y se libera el botón izquierdo
          del ratón.

 Borrar:
          Elimina la conexión existente entre dos neuronas. La
          operación es idéntica a la de adición de conexiones.

 Modificar Bloque de:
          Modifica los atributos del grupo de conexiones que se
          encuentran en el bloque seleccionado, mediante una caja
          de diálogos donde se pueden especificar los atributos
          para este grupo de conexiones. Primero se escoge el
          bloque de conexiones con la opción de Seleccionar
          Bloques del menú de Edición, y luego se elige esta
          opción.

 Consultar y Modificar:
          Muestra los atributos de la conexión que se seleccione.
          La operación es idéntica a la de adición de conexiones.
          Los atributos son mostrados en una caja de diálogos que
          permite la modificación de los mismos.

 Mostrar Conexiones:
          Si esta opción esta seleccionada la aplicación mostrará
          las líneas de conexiones, si no esta seleccionada no
          las mostrará.

Ventana:
Permite realizar la manipulación de las ventanas que se
encuentran abiertas, tales como cerrar todas las ventanas,
arreglar los iconos, etc.
Las opciones de este menú son:

 Cascada: 
          Organiza todas las ventanas en forma de cascada

 Distribuir:
          Organiza todas las ventanas de modo que ninguna quede
          cubierta por otra.

 Cerrar Todas:
          Cierra todas las ventanas que se encuentre abiertas.
          Pregunta si se desean almacenar los cambios de las
          redes neuronales que se han modificado.

 Organizar Iconos:
          Organiza las ventanas minimizadas (íconos) de modo que
          no se sobrepongan unas a las otras.

Ayuda:
Permite al usuario obtener información sobre el módulo de
entrenamiento, los comandos y otra información que facilitan el
uso del programa.

Un menú muy importante que contiene cada ventana es el Menú de
Control de la ventana, y se encuentra en la esquina superior-
izquierda de la ventana. Las opciones de este menú son:

 Minimizar:
          Minimiza la ventana (la lleva a un ícono).
 
 Maximizar:
          Maximiza la ventana (lleva la ventana a su tamaño
          máximo).

 Restaurar:
          Lleva la ventana a su tamaño previo.

 Acercar:
          Reduce el factor de escala para ver la red neuronal un
          poco más grande.


 Alejar:
          Aumente el factor de escala para ver la red neuronal un
          poco más pequeña.


B.2.2 Como construir una red neuronal
Los pasos típicos para la construcción de una red neuronal son
los siguientes:

A. Escoger la opción Nueva del menú Archivos.

B. Adicionar neuronas (ocultas, entrada y/o salida) mediante la
opción Adicionar del menú Neurona.

C. Adicionar conexiones entre neuronas utilizando la opción
Adicionar del menú Conexión.

D. Cambiar los atributos de las neuronas y las conexiones con la
opción Modificar de los menús Neurona y Conexión respectivamente.

E. Opcionalmente emplear las herramientas de edición avanzada,
menú Edición, si se necesitan.

F. Guardar la red neuronal en un archivo de disco, empleando la
opción Guardar o Guardar como del menú Archivos.

G. Salir del programa utilizando la opción Terminar del menú
Archivos. 

B.2.3 Representación gráfica de una red neuronal
Las neuronas son representadas por un círculo que en el interior
tiene una letra indicando el tipo de neurona (E: Entrada, O:
Oculta, S: Salida).

Las conexiones son representadas por líneas rectas que van desde
la parte frontal de la neurona origen a la parte posterior de la
neurona destino. El color de la conexión indica el signo de su
peso (azul: peso positivo, rojo : peso negativo). Las conexiones
que han sido fijadas aparecen como líneas punteadas.



B.3  USANDO UN-NeuroEntrenador
 
Es el módulo de entrenamiento de redes neuronales, en el cual se
carga una red para entrenarla permitiendo la utilización de
varios algoritmos.

Cuando se ha entrado a UN-NeuroEntrenador se encuentra una
ventana como la de la Ilustración 5.

La ventana consta de dos partes: una parte gráfica y otra de
información en formato texto.

La parte gráfica muestra la evolución del error durante el
proceso de entrenamiento. La gráfica superior corresponde a la
raíz del error cuadrático medio tanto para los patrones de
entrenamiento (línea continua) como para los patrones de prueba
de generalización (línea punteada). La gráfica inferior
corresponde al error máximo. La escala de estas gráficas se
ajusta dependiendo del valor del error.



La parte de información en formato texto señala el algoritmo de
entrenamiento en uso, el archivo que está cargado y los archivos
de patrones tanto de entrenamiento como de prueba de
generalización. En la parte inferior se muestra el valor de los
errores en cada iteración, además el número de iteraciones
acumuladas y los valores limites para el error y las iteraciones.

Esta ventana tiene una barra de menús con los siguientes
submenús:

B.3.1 Sumario de comandos
Archivos:
Permite realizar las operaciones de disco disponibles en la
aplicación como cargar y guardar los patrones y la red neuronal a
entrenar.
Las opciones del menú son:

 Cargar:  Carga una red neuronal almacenada en un archivo en
          disco a ser entrenada. Primero seleccione esta opción
          con lo cual aparecerá una caja de diálogos en la que
          puede especificar el nombre del archivo. El programa
          preguntará si se desea inicializar los pesos de las
          conexiones con valores aleatorios.

 Guardar: Almacena la red neuronal que está cargada en ese
          momento en un archivo en disco, la red neuronal puede
          estar entrenada parcial o  totalmente.

 Guardar Como...:
          Almacena la red neuronal en un archivo con el nombre
          que el usuario especifica, mediante una caja de
          diálogos.

 Inicializar pesos:
          Da valores aleatorios a los pesos de las conexiones y
          los umbrales de las neuronas.

 Cargar patrones:
          Carga un archivo de patrones existente en disco, el
          cual se utiliza para entrenar la red. Para cargar
          patrones previamente se debe cargar una red neuronal.

 Terminar:
          Cierra el módulo de entrenamiento, si la red neuronal
          cargada en ese momento no ha sido guardada, pregunta si
          se desea guardar o no.


Opciones: 
Permite especificar el algoritmo de entrenamiento, sus
parámetros, el número de iteraciones límite, la opción de
calcular el error de generalización, etc.

Las alternativas del menú son:

 Fijar límites:
          Mediante una caja de diálogo, permite especificar el
          número de iteraciones límites y el error límite que
          determinan hasta cuando iterará el algoritmo de
          aprendizaje.

 Especificar algoritmo de aprendizaje:
          Determina el algoritmo de aprendizaje utilizado para
          entrenar la red neuronal. Se utiliza una caja de
          diálogo en la cual el usuario escoge el algoritmo.

 Parámetros del algoritmo:
          Brinda la posibilidad de cambiar parámetros propios del
          algoritmo de aprendizaje en uso. 

 Error de generalización:
          Da la posibilidad de probar el grado de generalización
          de la red neuronal, con datos diferentes a los de
          entrenamiento. Una caja de diálogo se emplea para que
          se ingrese el nombre del archivo que contiene los
          patrones.

Entrenar:
Inicia el proceso de entrenamiento de la red neuronal, la barra
de menú es cambiada de modo que solo aparece la opción de Parar,
la cual interrumpe el proceso de entrenamiento.

Ayuda:
Permite al usuario obtener información sobre el módulo de
entrenamiento, los comandos y otra información que facilitan el
uso del programa.

B.3.2 Cómo entrenar una red neuronal
Los pasos para entrenar una red neuronal son los siguientes:

A. Diseñar una red neuronal y almacenarla en un archivo de disco,
usando UN-NeuroEditor.
B. Crear uno o varios archivos de patrones utilizando cualquier
editor de texto (que deje el archivo en formato ASCII). Los
patrones deben ser consistentes con la estructura de la red
neuronal (ver numeral 3.3).
C. Entrar a UN-NeuroEntrenador, escoger un algoritmo de
aprendizaje utilizando la opción Especificar Algoritmo de
Aprendizaje del menú Opciones.
D. Cargar el archivo de disco de la red neuronal, usando la
opción Cargar del menú Archivo.
E. Cargar el archivo de patrones de entrenamiento utilizando la
opción Cargar Patrones del menú Archivo.
F. Opcionalmente especificar archivo de patrones para la prueba
de generalización usando la opción Error de Generalización del
menú Opciones.
G. Fijar las iteraciones límite y el error límite mediante la
opción Fijar límites del menú Opciones.
H. Fijar los parámetros propios del algoritmo mediante la opción
Parámetros del Algoritmo del menú Opciones.
I. Comenzar el proceso de entrenamiento seleccionando la opción
Entrenar de la barra de menús.
J. Almacenar la red neuronal entrenada o parcialmente entrenada
en un archivo de disco, utilizando la opción Guardar del menú
Archivo.
K. Salir del programa mediante la opción Terminar del menú
Archivo.

Nota: Las instrucciones para cambiar los parámetros del algoritmo
de aprendizaje son propias de cada algoritmo, y pueden ser
consultadas en línea mediante la opción Ayuda de la barra de
menús.
 
B.3.3 Cómo crear un archivo de patrones
Un patrón es un vector de números reales de longitud n+m, donde n
es el número de neuronas de entrada y m es el número de neuronas
de salida de la red neuronal a entrenar.

Un archivo de patrones es una colección de vectores que
representan los patrones, los cuales se distribuyen uno por cada
línea. El formato de estos vectores debe ser el siguiente:
     ( p1 p2 .. pn pn+1 .. pn+m )
Por ejemplo:
          ( 0.9 0.1 0.9 )
es un patrón que puede servir para entrenar una red neuronal con
dos entradas y una salida o, una red neuronal con una entrada y
dos salidas.

La realización de un archivo de patrones se puede llevar a cabo
con un editor de texto (que genere archivos ASCII).




B.4 USANDO UN-NeuroSimulador

Es el módulo de simulación de redes neuronales, en el cual se
carga una red para simularla gráficamente o por medio de
archivos.

Cuando se ha entrado a UN-NeuroSimulador encuentra una ventana
como la de la ilustración 6.

Esta ventana tiene una barra de menús con los siguientes
submenús:

B.4.1 Sumario de comandos
Archivo: 
La opción de este menú es: 
 
 Cargar red: 
          Permite especificar mediante una caja de diálogos el
          archivo de la red neuronal a simular, luego pregunta el
          modo de simulación.
 
Opciones:
Este submenú da la posibilidad al usuario de simular la red de
una forma diferente a la gráfica. Las opciones de este menú son:

 Propagar archivo de patrones: 
          El usuario debe especificar un archivo de patrones de
          entrada que el módulo de simulación utiliza para
          propagarlos a través de la red neuronal generando un
          archivo de salida. (Solo utilizable para redes
          neuronales feedforward)

  Generar código C++:
          El módulo de simulación genera mediante esta opción un
          programa fuente en C++ que al ser compilado permite
          simular la red neuronal.

 Mostrar Conexiones:
          Si esta opción esta seleccionada la aplicación mostrará
          las líneas de conexiones, si no esta seleccionada no
          las mostrará.

Propagar:
Por medio de esta opción el programa propaga gráficamente los
valores fijados previamente por el usuario mediante la
utilización del ratón.

Ver:
Este submenú permite al usuario cambiar la escala de
visualización de la red neuronal.
 
 Acercar:
          Reduce el factor de escala para ver la red neuronal un
          poco más grande.

 Alejar:
          Aumenta el factor de escala para ver la red neuronal un
          poco más pequeña.

Ayuda:
Permite al usuario obtener información sobre el módulo de
simulación, los comandos y otra información que facilitan el uso
del programa.

B.4.2 Cómo simular una red neuronal
Los pasos para simular una red neuronal son los siguientes:

A. Crear y entrenar una red neuronal utilizando UN-NeuroEditor y
UN-NeuroEntrenador.
B. Entrar a UN-NeuroSimulador, cargar la red neuronal a simular
utilizando la opción Cargar del menú Archivo.
C. Cambiar valores de salida de las neuronas utilizando el ratón,
de la siguiente forma: posicione el cursor en la neurona a
modificar, presionando el botón izquierdo el valor de salida de
la neurona es cambiado a 0.1 o 0.9 alternadamente, presionando el
botón derecho aparece una caja de diálogo en la cual puede
modificar el valor de la salida.
D. Simular gráficamente la red neuronal paso a paso utilizando la
opción Propagar de la barra de menús.
E. Opcionalmente propagar un archivo de entradas (un archivo de
patrones con valores para las neuronas de entrada, ver numeral
3.3) ya creado, usando la opción Propagar archivo de patrones del
menú Opciones.
F. Opcionalmente crear un archivo con código en C++ que simule la
red neuronal, mediante la opción Generar código C++ del menú
Opciones.

B.4.3 Representación gráfica de la red neuronal

La representación es similar a la empleada en el módulo de diseño
y edición (UN-NeuroEditor), pero las neuronas cuya salida supera
el valor númerico 0.5 son mostradas en un color más oscuro.




                            C. EJEMPLOS


C.1 INTRODUCCION

En este anexo se muestran dos ejemplos de aplicación del
prototipo. Son ejemplos sencillos y su propósito es el de
ilustrar el uso de los tres módulos. Los archivos de las redes
neuronales utilizadas en los ejemplos, así como los archivos de
patrones utilizados para entrenarlas se adjuntan a la aplicación,
de modo que se pueda experimentar con dichos ejemplos. El primer
ejemplo corresponde a una red que resuelve el problema de la
paridad y el segundo a una red que resuelve un problema de
codificación, estos ejemplos se encuentran documentados en el
artículo de D.E. Rumelhart y sus colegas.

C.2 EL PROBLEMA DE LA PARIDAD

El problema consiste en determinar si el número de entradas que
tienen un valor lógico de 1 es par o impar. Aquí se resolverá el
problema para tres entradas,  de modo que la red neuronal para
este problema debe tener tres neuronas de entrada y una neurona
de salida. Las entradas y la salida son binarias, si la salida es
mayor de 0.5 indicará que el número de unos lógicos en la entrada
es impar, en caso contrario es par. 


La red neuronal diseñada usando UN-NeuroEditor se muestra en la
ilustración 16, esta red tiene tres neuronas de entrada, siete
neuronas ocultas y una neurona de salida. La definición de esta
red se encuentra en el archivo PARIDAD.NET el cual puede ser
editado utilizando UN-NeuroEditor.

Se utilizaron ocho patrones para entrenar la red, cada uno de los
patrones tiene cuatro valores, los tres primeros corresponden a
los datos de entrada y el último a la salida deseada. A
continuación se transcribe el archivo de patrones PARIDAD.PAT (el
valor 0.1 representa el cero lógico, y el valor 0.9 el uno
lógico).

     (  0.1  0.1  0.1  0.1  )
     (  0.1  0.1  0.9  0.9  )
     (  0.1  0.9  0.1  0.9  )
     (  0.1  0.9  0.9  0.1  )
     (  0.9  0.1  0.1  0.9  )
     (  0.9  0.1  0.9  0.1  )
     (  0.9  0.9  0.1  0.1  )
     (  0.9  0.9  0.9  0.9  )

Utilizando UN-NeuroEntrenador se entrenó la red neuronal haciendo
uso de los archivos de definición de la red y el archivo de
patrones. Se fijó un error límite de 0.1, la red aprendió en 260
iteraciones utilizando el algoritmo Back Propagation, con una
rata de aprendizaje de 1.0 y un momentum de 0.9.

En las ilustraciones 17 y 18 se muestran algunos resultados de la
simulación de la red ya entrenada, utilizando UN_NeuroSimulador.







C.3 EL PROBLEMA DE CODIFICACION

Este problema consiste en encontrar una codificación más compacta
para los patrones de entrada. En este caso se desea hacer una
correspondencia entre cadenas con una codificación de N bits y
cadenas con una codificación de Log2N bits. 

Para solucionar este problema se diseña una red neuronal con N
neuronas de entrada, con Log2N neuronas ocultas y con N neuronas
de salida. La red debe aprender a producir una salida idéntica a
la entrada, lo cual la obliga a encontrar una nueva codificación
en la capa oculta para los patrones de entrada. En este ejemplo
se diseñó una red que resolviera el problema para N = 4, con
cuatro neuronas de entrada, dos ocultas y cuatro de salida, esta
se muestra en la ilustración 19. ( el archivo en donde se
encuentra la definición de la red es CODIFI.NET, se puede editar
utilizando UN-NeuroEditor ). 


Se utilizaron cuatro patrones de tamaño ocho para entrenar la
red, estos patrones se encuentran en el archivo CODIFI.PAT y se
transcriben a continuación.
     (  0.9  0.1  0.1  0.1  0.9  0.1  0.1  0.1  )
     (  0.1  0.9  0.1  0.1  0.1  0.9  0.1  0.1  )
     (  0.1  0.1  0.9  0.1  0.1  0.1  0.9  0.1  )
     (  0.1  0.1  0.1  0.9  0.1  0.1  0.1  0.9  )

Los primeros cuatro datos corresponden a las entradas y los
últimos cuatro corresponden a las salidas.

Utilizando UN-NeuroEntrenador se entrenó la red con el algoritmo
BackPropagation, con una rata de aprendizaje de 1.5 y un momentum
de 0.9. El error límite se fijó en 0.1, la red aprendió en 45
iteraciones.

Se realizó la siulación de la red entrenada mediante
UN_NeuroSimulador, los resultados de la simulación se muestran en
las ilustraciones 20 a 23. 


Como se puede observar en los resultados de la
simulación, la red neuronal después de entrenada,
encontró una codificación interna para los patrones de entrada de
la siguiente manera:

    ENTRADAS               REPRESENTACION 
                              INTERNA   
    1  0  0  0                 0  0
    0  1  0  0                 1  0
    0  0  1  0                 0  1
    0  0  0  1                 1  1
