# Vod

Este proyecto es el trabajo final de la asignatura Procesadores de Lenguajes de la ULPGC por Fabio Catania y Roberto Díaz. Se trata del desarrollo de un procesador de lenguaje aplicando los principios, las técnicas y las herramientas expuestas en clase.
En particular, diseñamos primero los aspectos léxico, sintáctico y semántico del lenguaje Vod, inventado por nosotros mismos siguiendo los requisitos de la asignatura. Sus características se pueden encontrar en el documento “Vod_características_del_lenguaje”. En la carpeta Test se encuentran unos ejemplos de código Vod.
A continuación, implementamos un analizador léxico (mediante Flex), sintáctico (mediante Bison) y semántico (mediante la construcción de la tabla de los símbolos) y gestionamos la generación del código final de bajo nivel en lenguaje Q. Las características del lenguaje y de la maquina Q se encuentran en el archivo “./maqQ/Q-v3.7.3/Qman.txt”.
Además, controlamos también el análisis sintáctico empleando la técnica de descenso recursivo y el analizador léxico proporcionado por Flex. El código correspondiente a esta tarea y la memoria de esta parte se encuentra en la carpeta “recursive_descense”.
