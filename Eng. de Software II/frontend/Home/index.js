import React, { useState, useEffect, useHistory } from 'react';
import Navbar from '../components/Navbar';
import './style.css';
import api from '../services/api';

//import Judo from '../assets/images/judo.png'

function Home() {
    const [pais, setPais] = useState([]);

    function loadAllCountries(){
        api.get('/pais')
        .then(response => {
            console.log(response.data);
            setPais(response.data);
        })
        .catch(err => console.log(err))
    }

    function loadByContinent(){
        api.get('/join')
        .then(response => {
            console.log(response.data);
            setPais(response.data);
        })
        .catch(err => console.log(err))
    }

    function loadRepublics(){
        api.get('/like')
        .then(response => {
            console.log(response.data);
            setPais(response.data);
        })
        .catch(err => console.log(err))
    }

    function addCountry(){
        api.get('/add')
        .then(response => {
            // Outra coisa
        })
        .catch(err => console.log(err))
    }

    function deleteCountry(){
        api.get('/delete')
        .then(response => {
            // Outra coisa
        })
        .catch(err => console.log(err))
    }

    useEffect(() => {
        loadAllCountries();
    }, [pais]);

    return (
        <main id="home-page">
            <Navbar/>
            <div className="input-block">
                <button className="confirm-button" type="submit" onClick={loadByContinent}>
                    Pesquisar País por Continente
                </button>
                <button className="confirm-button" type="submit" onClick={loadRepublics}>
                    Pesquisar Países com República 
                </button>
                <button className="confirm-button" type="submit" onClick={loadAllCountries}>
                    Mostrar todos os países
                </button>
                <button className="confirm-button" type="submit" onClick={addCountry}>
                    Adiciona país
                </button>
                <button className="confirm-button" type="submit" onClick={deleteCountry}>
                    Deleta país
                </button>
            </div>
           
           <section>
               <h1>Países</h1>
               {pais.map(p => (
                    <div class="big-box">
                        <div class="medium-box">
                            <div class="small-box">
                                <div class="text-box">
                                    <p>{p.nome ? p.nome : ""}{p.nome ? "  -  " : ""}{p.nomecomum ? p.nomecomum : ""}</p>
                                </div>
                            </div>
                        </div>
                </div>
               ))}
           </section>
        </main>
    );
}

export default Home;