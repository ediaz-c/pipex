# Pipex
Pipex es un programa en C diseñado para simular la funcionalidad de los pipes en Linux. Proporciona una manera conveniente de ejecutar una secuencia de comandos de shell con redirección de entrada y salida utilizando pipes. El propósito principal de Pipex es replicar el comportamiento del siguiente comando de shell:
```
$> < infile comando1 | comando2 > outfile
```

## Uso
Para ejecutar Pipex, utiliza el siguiente formato:
```
$> ./pipex infile comando1 comando2 outfile
```
Pipex toma cuatro argumentos:
- **infile :** Nombre del archivo de entrada.
- **comando1 :** El primer comando de shell con sus parámetros.
- **comando2 :** El segundo comando de shell con sus parámetros.
- **outfile :** Nombre del archivo de salida

### Ejemplo
1. Ejecutar el siguiente comando:
```
$> ./pipex infile "ls -l" "wc -l" outfile
```
- Esto es equivalente al comando de shell:
```
$> < infile ls -l | wc -l > outfile
```

## Bonus
### Manejo de multiples Pipes
Pipex soporta múltiples pipes para secuencias de comandos más complejas. Para usar múltiples pipes, proporciona comandos adicionales:
```
$> ./pipex infile comando1 comando2 comando3 ... comandoN outfile
```
Esto se comportará como:
```
$> < infile comando1 | comando2 | comando3 ... | comandoN > outfile
```
### Aceptando << y >> con "here_doc"
Pipex acepta << y >> cuando el primer parámetro es "here_doc". Por ejemplo:
```
$> ./pipex here_doc LIMITADOR comando1 comando2 outfile
```
Esto se comportará como:
```
comando1 << LIMITADOR | comando2 >> outfile
```

## Compilación
### Mandatory
Para compilar la parte obligatoria de Pipex, utiliza el siguiente comando:
``` 
$> make
```
### Bonus
Para compilar la parte de bonus de Pipex, utiliza el siguiente comando:
```
$> make bonus
```

Esto generará el ejecutable **pipex**.

### Como ejecutar
Ejecuta el binario compilado de Pipex con el comando y los argumentos deseados:
```
$> ./pipex infile comando1 comando2 outfile
```
o para la versión de bonus:
```
$> ./pipex_bonus infile comando1 comando2 comando3 ... comandoN outfile
```