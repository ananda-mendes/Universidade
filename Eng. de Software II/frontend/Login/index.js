import React, { useState, useHistory } from 'react';
import './style.css';

function Login() {
    const [ email, setEmail ] = useState('');
    const [ senha, setSenha ] = useState('');

    function handleEmail(e) {
        e.preventDefault();
        setEmail(e.target.value);
    }

    function handleSenha(e) {
        e.preventDefault();
        setSenha(e.target.value);
    }

    function handleSubmit(e) {}

    return (
        <div id="login-page">
            <main>
                <form className="login-form">
                    <fieldset>
                        <legend>Fazer Login</legend>
                        <div className="input-block">
                            <label htmlFor="email">E-mail</label>
                            <input 
                                id="email"
                                type="email"
                                placeholder="..."
                                value={email}
                                onChange={handleEmail}
                                required={true}
                                className={''}
                            />
                        </div>
                        <div className="input-block senha">
                            <label htmlFor="senha">Senha</label>
                            <input 
                                id="senha"
                                type="password"
                                placeholder="..."
                                value={senha}
                                onChange={handleSenha}
                                required={true}
                                className={''}
                            />
                        </div>
                    </fieldset>

                    <button className="confirm-button" type="submit" onClick={e => handleSubmit(e)}>
                        Entrar
                    </button>
                </form>
            </main>
        </div>
    );
}

export default Login;