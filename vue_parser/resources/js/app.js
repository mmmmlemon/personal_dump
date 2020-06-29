require('./bootstrap');


window.Vue = require('vue');

import VueRouter from 'vue-router';
Vue.use(VueRouter);

import BootstrapVue from 'bootstrap-vue'
Vue.use(BootstrapVue)
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'


import VueAxios from 'vue-axios';
import axios from 'axios';
Vue.use(VueAxios, axios);

import UsersPageComp from './components/UsersPage.vue';
import SettingsComp from './components/Settings.vue'
import CreateUser from './components/CreateUser.vue';
import EditUser from './components/EditUser.vue';
import Stats from './components/Stats.vue';


import App from './App.vue';

Vue.component('pagination', require('laravel-vue-pagination'));

const routes = [
    {
        name: 'userspage',
        path: '/',
        component: UsersPageComp
    },
    {
        name: 'settings',
        path: '/settings',
        component: SettingsComp
    },
    {
        name: 'createUser',
        path: '/createUser',
        component: CreateUser
    },
    {
        name: 'editUser',
        path: 'editUser/:id',
        component: EditUser
    },
    {
        name: 'stats',
        path: 'statsUser/:id',
        component: Stats
    }
]

const router = new VueRouter({mode: 'history', routes: routes});
const app = new Vue(Vue.util.extend({ router }, App)).$mount('#app');