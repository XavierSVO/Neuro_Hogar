from flask import Flask, render_template
#render template ayuda a desplegar una pagina html
#inicializamos flask y lo guardamos dentro de un objeto
app = Flask(__name__)        #arhivo principal que arranca, guardada en app para poder crear ruta del servidor URL

#a partir del objeto podemos iniciar el servidor y crear rutas
#creamos la ruta
@app.route('/')                #pagina principal que se muestra, aqui le pasamos un nombre para crear la URL
def home():                    #puede llamarse index
    return render_template('principal.html')
#Creamos otra ruta
@app.route("/Login")            #ruta donde el usuario puede ver la pagina segun la ruta
def about():
    return render_template('login.html')
#necesitamos que nuestro servidor este escuchando siempre
#validacion para comprobar si el archivo principal se esta ejecutando
if __name__ == '__main__':
    app.run(debug ='true')
#con el debug cada vez que cambiamos codigo se volvera a iniciar  sin necesidad de apagarlolo
#para probar los cambios que hacemos
@app.route("/add")            #ruta donde el usuario puede ingresar usuarios segun la ruta
def add_contact():
    return 'add contact'

@app.route("/edit")            #ruta donde el usuario puede editar usuarios segun la ruta
def edit_contact():
    return 'edit contact'    
    
@app.route("/delete")            #ruta donde el usuario puede eliminar usuarios segun la ruta
def delete_contact():
    return 'delete contact'     

@app.route("/status")            #ruta donde el usuario puede colocar el estado del foco segun la ruta
def status_home():
    return 'status home'     