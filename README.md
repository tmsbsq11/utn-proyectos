
# Proyectos Universidad

Este repositorio es para que todos podamos subir nuestros proyectos y trabajos de la universidad.

## Pasos para empezar

### 1. **Clonar el repo**

Hay que clonar el repo primero en la computadora para trabajar en él.

1. Abrir la terminal o Git Bash.
2. Navegar a la carpeta donde querés tener el repo. Por ejemplo:

   ```bash
   cd /ruta/donde/queres/guardar
   ```
   O abris la terminal directamente en la carpeta donde lo querés clonar.

3. Clonar el repositorio con este comando:

   ```bash
   git clone https://github.com/tmsbsq11/utn-proyectos.git
   ```

### 2. **Navegar al repositorio**

Una vez clonado el repositorio, ir a la carpeta del repositorio con el siguiente comando:

```bash
cd utn-proyectos
```

### 3. **Crear tu carpeta**

Si no tenés una carpeta personal, creala con este comando:

```bash
mkdir mi_nombre
```
Github borra las carpetas vacias automáticamente, crea un archivo dentro de esa carpeta que se llame .gitkeep

### 4. **Subir tus proyectos**

Ahora, agrega tus proyectos o archivos que quieras subir adentro de la carpeta que creaste o con tu nombre. Una vez los tengas ahí, hace lo siguiente:

1. **Agrega los archivos al repositorio**:

   ```bash
   git add .
   ```

   Esto le dice a Git que los archivos que agregaste deben ser registrados. Hacelo dentro de la carpeta con tu nombre.

2. **Hacer un commit de los archivos**:

   ```bash
   git commit -m "Agregados mis proyectos"
   ```

   El `commit` es como un "guardar" en Git. Cada vez que hagas cambios, tenés que hacer un commit para que se registren.

3. **Subir cambios a GitHub**:

   ```bash
   git push origin main
   ```

   Esto sube todo lo que hiciste a GitHub, para que podamos acceder y verlos.

### 5. **Ver los cambios de los demás**

Si otros subieron sus proyectos o hicieron cambios, podés actualizar tu copia local del repositorio para bajar los últimos cambios:

```bash
git pull origin main
```

Baja los cambios más recientes desde GitHub a tu computadora.


## Consejos

- **No borres ni modifiques las carpetas de los demás**. Cada uno tiene su propia carpeta.
- Usa siempre tu carpeta para tus proyectos y no pongas los archivos de otros en la tuya.



