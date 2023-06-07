/* import React, { useState, useHistory } from 'react';
import Select from 'react-select'
import api from '../../../services/api';
import './style.css';

function Register() {
    const [ nome, setNome ] = useState('');
    const [ abreviacao, setAbreviacao ] = useState('');
    const [ nomeOficial, setNomeOficial ] = useState('');

    const continente = [
        { label: 'Europa' },
        { label: 'Ásia'},
        { label: 'África'},
        { label: 'América'},
        { label: 'Oceania'},
    ];

    function handleNome(e) {
        e.preventDefault();
        setNome(e.target.value);
    }

    function handleAbreviacao(e) {
        e.preventDefault();
        setAbreviacao(e.target.value);
    }

    function handleNomeOficial(e) {
        e.preventDefault();
        setNomeOficial(e.target.value);
    }

    async function handleSubmit(e) {
        try {
            const data = new FormData();
            data.append("nome", nome);
            data.append("nomeoficial", nomeOficial);
            data.append("abreviacao", abreviacao);
            data.append("continente", continente);

            await api.post(`/`, data);

            setNome('');
            setAbreviacao('');
            setNomeOficial('');
            alert('Pais criado com sucesso!');
        } catch (error) {
            console.log(error);
        }
    }

    return (
        <div id="register-page">
            <main>
                <form className="register-form">
                    <fieldset>
                        <legend>Cadastro País</legend>
                        <div className="input-block">
                            <label htmlFor="nome">Nome</label>
                            <input 
                                id="nome"
                                type="nome"
                                placeholder="..."
                                value={nome}
                                onChange={handleNome}
                                required={true}
                                className={''}
                            />
                        </div>
                        <div className="input-block">
                            <label htmlFor="nome-oficial">Nome Oficial</label>
                            <input 
                                id="nome-oficial"
                                type="nome-oficial"
                                placeholder="..."
                                value={nomeOficial}
                                onChange={handleNomeOficial}
                                required={true}
                                className={''}
                            />
                        </div>
                        <div className="input-block">
                            <label htmlFor="abreviacao">Abreviação</label>
                            <input 
                                id="abreviacao"
                                type="abreviacao"
                                placeholder="..."
                                value={abreviacao}
                                onChange={handleAbreviacao}
                                required={true}
                                className={''}
                            />
                        </div>
                        <div className="input-block">
                            <label htmlFor="continente">Continente</label>
                            <Select className="continente" options={continente} />
                            
                        </div>
                        
                    </fieldset>

                    <button className="confirm-button" type="submit" onClick={e => handleSubmit(e)}>
                        Cadastrar
                    </button>
                </form>
            </main>
        </div>
    );
}

export default Register; */