import React from 'react';
import {  BrowserRouter, Router, Route, Routes  } from 'react-router-dom';



import Home from './Home/index';
import Login from './Login';
import Register from './País/Cadastro';
import Edit from './País/Editar';

const RoutesOlympus = () => {
    return(
        <BrowserRouter>
             <Routes>
                <Route exact path="/login" element={<Login/>}/>
                <Route exact path="/" element={<Home/>} /> 
                <Route exact path="/register" element ={<Register/>} />
                <Route exact path="/edit" element ={<Edit/>} />
            </Routes>
        </BrowserRouter>
    );
}

export default RoutesOlympus;