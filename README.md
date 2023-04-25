# ft_irc
The goal of this project is to make you write your own IRC server

## IRC Client

- [Weechat](https://weechat.org/download/)

## Pending tasks

Necesitamos unos utils que nos den funciones:

- [] split (la linea 119 de command va a fallar hasta que hagas la función split)
- [] tolowercase (hasta que no lo tengamos, los nicks siempre en mayúsculas)
- [] El TODO de la linea 145 de sockets
- [] Crear el msg de ResultCmd, según el error, para todos los errores posibles
- [] No veo el motivo por el que si hago yo la carga de nick y user de un usuario sí que funciona (es lo activado ahora en prueba), pero no si se hace desde el socket

## Debug

Añadir el flag -D_GLIBCXX_DEBUG al makefile

Crear el archivo launch.json. Si en vez de crearse directamente, da opciones, seleccionar cualquiera de ellas:

<img width="800" alt="image" src="https://user-images.githubusercontent.com/50380855/204127434-7960a078-b72a-445a-abc6-397a47f3f5e6.png">

Sustituir el contenido de launch.json por:

```csharp
{
    // Use IntelliSense para saber los atributos posibles.
    // Mantenga el puntero para ver las descripciones de los existentes atributos.
    // Para más información, visite: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Iniciar",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/pruebas",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Habilitar la impresión con sangría para gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description":  "Establecer tipo de desensamblado en Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        },
        {
            "name": "(gdb) Asociación de canalización",
            "type": "cppdbg",
            "request": "attach",
            "program": "Escriba el nombre del programa; por ejemplo, ${workspaceFolder}/a.out.",
            "processId": "${command:pickRemoteProcess}",
            "pipeTransport": {
                "debuggerPath": "/usr/bin/gdb",
                "pipeProgram": "/usr/bin/ssh",
                "pipeArgs": [],
                "pipeCwd": ""
            },
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Habilitar la impresión con sangría para gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description":  "Establecer tipo de desensamblado en Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        },
        {
            "name": "(gdb) Adjuntar",
            "type": "cppdbg",
            "request": "attach",
            "program": "${workspaceFolder}/pruebas",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Habilitar la impresión con sangría para gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description":  "Establecer tipo de desensamblado en Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }

    ]
}
```
Una vez guardado el archivo ya está disponible la depuración. Pero va a ejecutarlo sobre el programa compilado (hacer make antes)

<img width="155" alt="image" src="https://user-images.githubusercontent.com/50380855/204127535-b26cb11f-927a-412d-bcf1-fc5dbfad79de.png">

