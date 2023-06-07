const express = require('express');

const db = require("./database");

module.exports = {

    async index (req, res) {

        const response = await db.query("select * from Pais order by nomecomum");
        res.status(200).send(response.rows);
    },

    async join (req, res) {
        
        const response = await db.query("select C.nome, P.abreviacao, P.nomecomum from Pais as P, Continente as C where P.continente = C.cor order by C.nome")
        console.log(response);
        res.status(200).send(response.rows);
    },

    async like (req, res) {
        
        const response = await db.query("select P.nomecomum from Pais as P where P.nomeoficial like 'República%' order by P.nomecomum");
        console.log(response);
        res.status(200).send(response.rows);
    },

    async add (req, res) {

        const response = await db.query("INSERT INTO Pais VALUES ('BRA', 'Vermelho', 'República Federativa do Brasil', 'Brasil') ");
        console.log(response);
        res.status(200).send(response);
    },

    async delete (req, res) {
        
        const response = await db.query("delete from Pais where nomecomum like '%Brasil%' ");
        console.log(response);
        res.status(200).send(response);
    },

    async del (req, res) {

        const { id } = req.params;

        const response = await db.query(`delete from Pais where nomecomum like '%${id}%' `);
        console.log(response);
        res.status(200).send(response);

    }
}
