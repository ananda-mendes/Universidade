const express = require('express');
const routes = express.Router();

const controller = require('./controller');

routes.get('/', (req, res) => {
    return res.send({msg: 'Get do router'});
});

routes.get('/pais', controller.index);
routes.get('/join', controller.join);
routes.get('/like', controller.like);
routes.get('/add', controller.add);
routes.get('/delete', controller.delete);

routes.delete('/del/:id', controller.del);

module.exports = routes;