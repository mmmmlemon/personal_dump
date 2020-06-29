<template>

<div>
  <b-card title="Card Title" no-body>
    <b-card-header header-tag="nav">
      <b-nav card-header tabs align="center">
        <b-nav-item v-bind:active="currentPage=='users'">
            <router-link to="/" class="whiteText">Users</router-link>
        </b-nav-item>
        <b-nav-item v-bind:active="currentPage=='settings'">
            <router-link to="/settings">Settings</router-link>
        </b-nav-item>
      </b-nav>
    </b-card-header>

    <b-card-body class="text-center">
        <router-view>

        </router-view>
    </b-card-body>
  </b-card>
</div>
</template>


<script>
export default {

    data: function(){
        return{
            currentPage: this.$router.currentRoute.path
        }
      
    }
    
}
</script>

