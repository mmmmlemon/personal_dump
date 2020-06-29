// HomeComponent.vue

<template>
  <div class="row justify-content-center">
      <div class="col-md-8">
         <div>
             <div>
  <b-button v-b-modal.modal-1>Launch demo modal</b-button>

  <b-modal id="modal-1" title="BootstrapVue">
    <p class="my-4">Hello from modal!</p>
  </b-modal>
</div>
         </div>
      </div>
  </div>
</template>

<script>
    export default {
        mounted() {
           
        }
    }
</script>