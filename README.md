# LightDependentResistor

Simplifica la lectura de sensores LDR

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/LightDependentResistor.git .
```

Esto creara el directorio LightDependentResistor de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la última vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la última versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la última versión siguiendo los pasos de Selección de versión

## Uso

La libreria incluye una clase LightDependentResistor instanciable. LightDependentResistor se configura con dos parametros, uno para indicar el pin que esta conectado al LDR y será usado para leer el estado, y otro parametro opcional que recibira un callback que será invocado cuando se detecte que ocurrió un cambio en el estado del pin desde la ultima vez que se corroboró la lectura.

``` c++
LightDependentResistor ldr(pin, ChangeEvent);
```

Para verificar el estado del LDR se debe recurrir al metodo Read. Si durante la lectura, se detecta que el estado ha cambiado desde la ultima vez que se ejecuto Read(), entonces se tratará de invocar al callback asociado al evento OnChanged.

``` c++
int value = ldr.Read();
```

## Links

- [Cambios de version](CHANGELOG.md)
- [Repositorio](https://gitlab.com/arduinolibraries/LightDependentResistor/-/tree/master)